//
// Created by Lennert Steyaert on 24/04/2022.
//

#include "Model/Cube/CubeModel.h"



CubeModel::CubeModel(glm::vec3 dimensions,Texture * texture_1, Texture * texture_2, glm::vec3 position, ShaderType type,std::vector<BaseModel*> &light) : BaseModel(type,light){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->position =  position;

    fillVertices(dimensions);


    this->indices = std::vector<GLuint>
            {
                    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35
//                            // First surface
//                            0, 1, 3, // first triangle
//                            1, 2, 3, // second triangle
//                            // Second surface
//                            4, 5, 7, // first triangle
//                            5, 6, 7, // second triangle
//                            // Third surface
//                            8, 9, 11,  // first triangle
//                            9, 10, 11, // second triangle
//                            // Fourth surface
//                            12, 13, 15,  // first triangle
//                            13, 14, 15,  // second triangle
//                            // Fifth surface
//                            16, 17, 19,  // first triangle
//                            17, 18, 19,  // second triangle
//                            // Sixt surface
//                            20, 21, 23,  // first triangle
//                            21, 22, 23  // second triangle
            };

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());
    this->ebo = std::make_unique<EBO>(indices,indices.size());




    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 14 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 14 * sizeof(float), (void*)(3 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 2, 2, GL_FLOAT, 14 * sizeof(float), (void*)(6 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 3, 3, GL_FLOAT, 14 * sizeof(float), (void*)(8 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 4, 3, GL_FLOAT, 14 * sizeof(float), (void*)(11 * sizeof(float)));

    //vao.linkAttrib(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    vao->unbind();
    vbo->unbind();
    ebo->unbind();


    this->texture_1 = texture_1;
    this->texture_2 = texture_2;


    this->bb = BoundingBox();
    this->bb.centre = position;
    this->bb.dimensions  =  glm::vec3(dimensions.x,dimensions.y,dimensions.z);

    vertices.clear();
}



void CubeModel::fillVertices(glm::vec3 dimensions){

    // positions
    glm::vec3 pos1(-1.0f,  1.0f, 0.0f);
    glm::vec3 pos2(-1.0f, -1.0f, 0.0f);
    glm::vec3 pos3( 1.0f, -1.0f, 0.0f);
    glm::vec3 pos4( 1.0f,  1.0f, 0.0f);


    pos1 = glm::vec3(-dimensions.x/2,+dimensions.y/2,-dimensions.z/2);
    pos2 = glm::vec3(-dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
    pos3 = glm::vec3(dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
    pos4 = glm::vec3(dimensions.x/2,dimensions.y/2,-dimensions.z/2);

    // texture coordinates
    glm::vec2 uv1(0.0f, 1.0f);
    glm::vec2 uv2(0.0f, 0.0f);
    glm::vec2 uv3(1.0f, 0.0f);
    glm::vec2 uv4(1.0f, 1.0f);
    // normal vector
    glm::vec3 nm(0.0f, 0.0f, -1.0f);

    // calculate tangent/bitangent vectors of both triangles
    glm::vec3 tangent1, bitangent1;
    glm::vec3 tangent2, bitangent2;

    // triangle 1
    // ----------
    glm::vec3 edge1 = pos2 - pos1;
    glm::vec3 edge2 = pos3 - pos1;
    glm::vec2 deltaUV1 = uv2 - uv1;
    glm::vec2 deltaUV2 = uv3 - uv1;


    float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    // triangle 2
    // ----------
    edge1 = pos3 - pos1;
    edge2 = pos4 - pos1;
    deltaUV1 = uv3 - uv1;
    deltaUV2 = uv4 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);


    bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);


    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos2.x);
    this->vertices.push_back(pos2.y);
    this->vertices.push_back(pos2.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);


    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);


    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

//    this->vertices.push_back(uv2.x);
//    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos4.x);
    this->vertices.push_back(pos4.y);
    this->vertices.push_back(pos4.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    pos1 = glm::vec3(-dimensions.x/2,+dimensions.y/2,dimensions.z/2);
    pos2 = glm::vec3(-dimensions.x/2,-dimensions.y/2,dimensions.z/2);
    pos3 = glm::vec3(dimensions.x/2,-dimensions.y/2,dimensions.z/2);
    pos4 = glm::vec3(dimensions.x/2,dimensions.y/2,dimensions.z/2);

    //    this->vertices.push_back(-dimensions.x/2);
//    this->vertices.push_back(-dimensions.y/2);
//    this->vertices.push_back(-dimensions.y/2);


    // normal vector
    nm = glm::vec3(0.0f, 0.0f, 1.0f);


    // triangle 1
    // ----------
    edge1 = pos2 - pos1;
    edge2 = pos3 - pos1;
    deltaUV1 = uv2 - uv1;
    deltaUV2 = uv3 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    // triangle 2
    // ----------
    edge1 = pos3 - pos1;
    edge2 = pos4 - pos1;
    deltaUV1 = uv3 - uv1;
    deltaUV2 = uv4 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);


    bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);


    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos2.x);
    this->vertices.push_back(pos2.y);
    this->vertices.push_back(pos2.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos4.x);
    this->vertices.push_back(pos4.y);
    this->vertices.push_back(pos4.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);



//    pos1 = glm::vec3(-dimensions.x/2,+dimensions.y/2,-dimensions.z/2);
//    pos2 = glm::vec3(-dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
//    pos3 = glm::vec3(dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
//    pos4 = glm::vec3(dimensions.x/2,dimensions.y/2,-dimensions.z/2);

    pos1 = glm::vec3(-dimensions.x/2,dimensions.y/2,dimensions.z/2);
    pos2 = glm::vec3(-dimensions.x/2,dimensions.y/2,-dimensions.z/2);
    pos3 = glm::vec3(dimensions.x/2,dimensions.y/2,-dimensions.z/2);
    pos4 = glm::vec3(dimensions.x/2,dimensions.y/2,dimensions.z/2);

    //    this->vertices.push_back(-dimensions.x/2);
//    this->vertices.push_back(-dimensions.y/2);
//    this->vertices.push_back(-dimensions.y/2);


    // normal vector
    nm = glm::vec3(0.0f, 1.0f, 0.0f);


    // triangle 1
    // ----------
    edge1 = pos2 - pos1;
    edge2 = pos3 - pos1;
    deltaUV1 = uv2 - uv1;
    deltaUV2 = uv3 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    // triangle 2
    // ----------
    edge1 = pos3 - pos1;
    edge2 = pos4 - pos1;
    deltaUV1 = uv3 - uv1;
    deltaUV2 = uv4 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);


    bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);


    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos2.x);
    this->vertices.push_back(pos2.y);
    this->vertices.push_back(pos2.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos4.x);
    this->vertices.push_back(pos4.y);
    this->vertices.push_back(pos4.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);


    pos1 = glm::vec3(-dimensions.x/2,-dimensions.y/2,dimensions.z/2);
    pos2 = glm::vec3(-dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
    pos3 = glm::vec3(dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
    pos4 = glm::vec3(dimensions.x/2,-dimensions.y/2,dimensions.z/2);

    // normal vector
    nm = glm::vec3(0.0f, -1.0f, 0.0f);


    // triangle 1
    // ----------
    edge1 = pos2 - pos1;
    edge2 = pos3 - pos1;
    deltaUV1 = uv2 - uv1;
    deltaUV2 = uv3 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    // triangle 2
    // ----------
    edge1 = pos3 - pos1;
    edge2 = pos4 - pos1;
    deltaUV1 = uv3 - uv1;
    deltaUV2 = uv4 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);


    bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);


    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos2.x);
    this->vertices.push_back(pos2.y);
    this->vertices.push_back(pos2.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos4.x);
    this->vertices.push_back(pos4.y);
    this->vertices.push_back(pos4.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);


// -+ -- +- ++

    pos1 = glm::vec3(dimensions.x/2,-dimensions.y/2,dimensions.z/2);
    pos2 = glm::vec3(dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
    pos3 = glm::vec3(dimensions.x/2,dimensions.y/2,-dimensions.z/2);
    pos4 = glm::vec3(dimensions.x/2,dimensions.y/2,dimensions.z/2);

    // normal vector
    nm = glm::vec3(1.0f, 0.0f, 0.0f);

    // triangle 1
    // ----------
    edge1 = pos2 - pos1;
    edge2 = pos3 - pos1;
    deltaUV1 = uv2 - uv1;
    deltaUV2 = uv3 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    // triangle 2
    // ----------
    edge1 = pos3 - pos1;
    edge2 = pos4 - pos1;
    deltaUV1 = uv3 - uv1;
    deltaUV2 = uv4 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);


    bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);


    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos2.x);
    this->vertices.push_back(pos2.y);
    this->vertices.push_back(pos2.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos4.x);
    this->vertices.push_back(pos4.y);
    this->vertices.push_back(pos4.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);


    pos1 = glm::vec3(-dimensions.x/2,-dimensions.y/2,dimensions.z/2);
    pos2 = glm::vec3(-dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
    pos3 = glm::vec3(-dimensions.x/2,dimensions.y/2,-dimensions.z/2);
    pos4 = glm::vec3(-dimensions.x/2,dimensions.y/2,dimensions.z/2);


    // normal vector
    nm = glm::vec3(-1.0f, 0.0f, 0.0f);

    // triangle 1
    // ----------
    edge1 = pos2 - pos1;
    edge2 = pos3 - pos1;
    deltaUV1 = uv2 - uv1;
    deltaUV2 = uv3 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    // triangle 2
    // ----------
    edge1 = pos3 - pos1;
    edge2 = pos4 - pos1;
    deltaUV1 = uv3 - uv1;
    deltaUV2 = uv4 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);


    bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);


    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos2.x);
    this->vertices.push_back(pos2.y);
    this->vertices.push_back(pos2.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv3.x);
    this->vertices.push_back(uv3.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent1.x);
    this->vertices.push_back(tangent1.y);
    this->vertices.push_back(tangent1.z);

    this->vertices.push_back(bitangent1.x);
    this->vertices.push_back(bitangent1.y);
    this->vertices.push_back(bitangent1.z);

    this->vertices.push_back(pos1.x);
    this->vertices.push_back(pos1.y);
    this->vertices.push_back(pos1.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv2.x);
    this->vertices.push_back(uv2.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos3.x);
    this->vertices.push_back(pos3.y);
    this->vertices.push_back(pos3.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv4.x);
    this->vertices.push_back(uv4.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);

    this->vertices.push_back(pos4.x);
    this->vertices.push_back(pos4.y);
    this->vertices.push_back(pos4.z);

    this->vertices.push_back(nm.x);
    this->vertices.push_back(nm.y);
    this->vertices.push_back(nm.z);

    this->vertices.push_back(uv1.x);
    this->vertices.push_back(uv1.y);

    this->vertices.push_back(tangent2.x);
    this->vertices.push_back(tangent2.y);
    this->vertices.push_back(tangent2.z);

    this->vertices.push_back(bitangent2.x);
    this->vertices.push_back(bitangent2.y);
    this->vertices.push_back(bitangent2.z);
}


CubeModel::~CubeModel() {
    std::cout << "deleted cubemodel" << std::endl;
    vao.release();
    vbo.release();
    ebo.release();
}


void CubeModel::updatePosition(glm::vec3 pos){
    this->position = pos;
}

void CubeModel::setTextures(Shader* shader) {
    this->texture_1->texUnit(shader,"material.diffuse");
    this->texture_2->texUnit(shader,"material.specular");
}

void CubeModel::setLights(Shader* shader) {

    shader->setFloat("material.shininess", 32.0f);
    shader->setBool("directionLightState", false);
    shader->setBool("pointLightState", false);
    shader->setBool("spotLightState", false);


    uint pos = 0;
    for(auto l:light){
        l->setupShader(shader,pos);
    }

    if(pos > 0){
        shader->setBool("pointLightState", true);
        shader->setInt("numberOfPointLights", pos);
    }
}

//
//void TestModel::setPositionLight(glm::vec3 positionLight){
//    this->positionLight = positionLight;
//}

void CubeModel::draw(Shader *shader) {
    shader->use();

    glm::mat4 m = glm::mat4(1.0f);
    m = glm::translate(m, position); // translate it down so it's at the center of the scene
    shader->setMat4("model", m);

//    std::cout << "pos: " << position.x << std::endl;
//
//    std::cout << "pos light: " << positionLight.z << std::endl;

    setTextures(shader);


    setLights(shader);

    this->texture_1->bind();
    this->texture_2->bind();

    this->vao->bind();
    this->ebo->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, static_cast<unsigned int>(indices.size()));

    show = true;
}

void CubeModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}

