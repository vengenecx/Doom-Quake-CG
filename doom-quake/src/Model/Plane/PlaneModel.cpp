//
// Created by Lennert Steyaert on 25/04/2022.
//

#include "Model/Plane/PlaneModel.h"


PlaneModel::PlaneModel(glm::vec3 dimensions, bool wall, bool inside, Texture * texture_1, Texture* texture_2, glm::vec3 pos, ShaderType type, std::vector<BaseModel*> &light, bool reflect) : BaseModel(type,light), reflect(reflect){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();
    this->position =  pos;

    this->texture_1 = texture_1;
    this->texture_2 = texture_2;

    fillVertices(dimensions, wall, inside);

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());

    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 14 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 14 * sizeof(float), (void*)(3 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 2, 2, GL_FLOAT, 14 * sizeof(float), (void*)(6 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 3, 3, GL_FLOAT, 14 * sizeof(float), (void*)(8 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 4, 3, GL_FLOAT, 14 * sizeof(float), (void*)(11 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    vao->unbind();
    vbo->unbind();


    this->bb = BoundingBox();
    this->bb.centre = position;
    this->bb.dimensions = glm::vec3(dimensions.x,dimensions.y,dimensions.z);

    this->vertices.clear(); // Clear vertices
}


PlaneModel::~PlaneModel() {
    std::cout << "deleted cubemodel" << std::endl;
    vao.release();
    vbo.release();
}

void PlaneModel::fillVertices(glm::vec3 dimensions, bool wall, bool inside) {

    glm::vec3 nm, pos1, pos2, pos3, pos4;

    glm::vec2 uv1(0.0f, 1.0f);
    glm::vec2 uv2(0.0f, 0.0f);
    glm::vec2 uv3(1.0f, 0.0f);
    glm::vec2 uv4(1.0f, 1.0f);

    float size = this->texture_1->getSize();
     if(dimensions.y == 0){
         float x = dimensions.x / size;
         float z = dimensions.z / size;
         uv1.y = z;
         uv3.x = x;
         uv4.x = x;
         uv4.y = z;
    } else if (dimensions.x == 0){
        float y = dimensions.y / size;
        float z = dimensions.z / size;
        uv1.y = y;
        uv3.x = z;
        uv4.x = z;
        uv4.y = y;
    } else if(dimensions.z == 0){
        float x = dimensions.x / size;
        float y = dimensions.y / size;
        uv1.y = y;
        uv3.x = x;
        uv4.x = x;
        uv4.y = y;
    } else{
         float y = dimensions.y / size;
         float z = dimensions.z / size;
         uv1.y = y;
         uv3.x = z;
         uv4.x = z;
         uv4.y = y;
     }

    // // texture coordinates
    // if(dimensions.y == 0){
    //     if(dimensions.x >= dimensions.z){
    //         // we have a floor or a roof
    //         uv1 = glm::vec2(0.0f, dimensions.x/dimensions.z);
    //         uv2 = glm::vec2(0.0f, 0.0f);
    //         uv3 = glm::vec2(dimensions.x/dimensions.z, 0.0f);
    //         uv4 = glm::vec2(dimensions.x/dimensions.z, dimensions.x/dimensions.z);
    //     } else if (dimensions.x <= dimensions.z){
    //            // we have a floor or a roof
    //         uv1 = glm::vec2(0.0f, dimensions.z/dimensions.x);
    //         uv2 = glm::vec2(0.0f, 0.0f);
    //         uv3 = glm::vec2(dimensions.z/dimensions.x, 0.0f);
    //         uv4 = glm::vec2(dimensions.z/dimensions.x, dimensions.z/dimensions.x);
    //     }
    // } // else if (dimensions.x == 0) {
    //     // we have a wall
    //     uv1 = glm::vec2(0.0f, dimensions.z);
    //     uv2 = glm::vec2(0.0f, 0.0f);
    //     uv3 = glm::vec2(dimensions.y, 0.0f);
    //     uv4 = glm::vec2(dimensions.y, dimensions.z);
    // } else if (dimensions.z == 0){
    //     // we have a wall
    //     uv1 = glm::vec2(0.0f, dimensions.x);
    //     uv2 = glm::vec2(0.0f, 0.0f);
    //     uv3 = glm::vec2(dimensions.y, 0.0f);
    //     uv4 = glm::vec2(dimensions.y, dimensions.x);
    // }

    // calculate tangent/bitangent vectors of both triangles
    glm::vec3 tangent1, bitangent1;
    glm::vec3 tangent2, bitangent2;

    glm::vec3 edge1, edge2;
    glm::vec2 deltaUV1, deltaUV2;

    // Normals based on wall orientation
    if(wall){
        if(inside){
            if(dimensions.z == 0){
                nm = glm::vec3 (0.0f, 0.0f, 1.0f);
            } else {
                nm = glm::vec3 (1.0f, 0.0f, 0.0f);
            }

        }  else{
            if(dimensions.z == 0){
                nm = glm::vec3 (-0.0f, 0.0f, -1.0f);
            } else{
                nm = glm::vec3 (-1.0f, 0.0f, 0.0f);
            }

        }
    }  else{
        if(inside){
            nm = glm::vec3 (0.0f, 1.0f, 0.0f);
        }  else{
            nm = glm::vec3 (0.0f, -1.0f, 0.0f);
        }
    }

    if(wall){

        pos1 = glm::vec3(-dimensions.x/2,+dimensions.y/2,dimensions.z/2);
        pos2 = glm::vec3(-dimensions.x/2,-dimensions.y/2,dimensions.z/2);
        pos3 = glm::vec3(dimensions.x/2,-dimensions.y/2,-dimensions.z/2);
        pos4 = glm::vec3(dimensions.x/2,+dimensions.y/2,-dimensions.z/2);

        // triangle 1
        // ----------
        edge1 = pos2 - pos1;
        edge2 = pos3 - pos1;
        deltaUV1 = uv2 - uv1;
        deltaUV2 = uv3 - uv1;

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
    } else{

        pos1 = glm::vec3(-dimensions.x/2,+dimensions.y/2,dimensions.z/2);
        pos2 = glm::vec3(-dimensions.x/2,+dimensions.y/2,-dimensions.z/2);
        pos3 = glm::vec3(dimensions.x/2,+dimensions.y/2,-dimensions.z/2);
        pos4 = glm::vec3(dimensions.x/2,+dimensions.y/2,dimensions.z/2);

        // triangle 1
        // ----------
        edge1 = pos2 - pos1;
        edge2 = pos3 - pos1;
        deltaUV1 = uv2 - uv1;
        deltaUV2 = uv3 - uv1;

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
    }

}

//void PlaneModel::generateBoundingbox() {
//    float x_min = this->vertices[0];
//    float x_max = this->vertices[0];
//    float y_min = this->vertices[1];
//    float y_max = this->vertices[1];
//    float z_min = this->vertices[2];
//    float z_max = this->vertices[2];
//
//    for(int i=0; i<this->vertices.size()-8; i+=8){
//        if(x_min > this->vertices[i])
//            x_min = this->vertices[i];
//        if(x_max < this->vertices[i])
//            x_max = this->vertices[i];
//
//        if(y_min > this->vertices[i+1])
//            y_min = this->vertices[i+1];
//        if(y_max < this->vertices[i+1])
//            y_max = this->vertices[i+1];
//
//        if(z_min > this->vertices[i+2])
//            z_min = this->vertices[i+2];
//        if(z_max < this->vertices[i+2])
//            z_max = this->vertices[i+2];
//    }
//
////    if(y_min ==  y_max){
////        this->bb  = BoundingBox{position,glm::vec3(x_max-x_min,0.1,z_max-z_min)};
////    } else if(x_min == x_max){
////        this->bb  = BoundingBox{position,glm::vec3(0.1,y_max-y_min,z_max-z_min)};
////    } else{
////        this->bb  = BoundingBox{position,glm::vec3(x_max-x_min,y_max-y_min,0.1)};
////    }
//
//    this->bb  = BoundingBox{position,glm::vec3(x_max-x_min,y_max-y_min,z_max-z_min)};
//}

void PlaneModel::updatePosition(glm::vec3 pos){
    this->position = pos;
}

void PlaneModel::setTextures(Shader* shader) {
    this->texture_1->texUnit(shader,"material.diffuse");
    this->texture_2->texUnit(shader,"material.specular");
}

void PlaneModel::setLights(Shader* shader) {
    //Explained in planemodel
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

void PlaneModel::draw(Shader *shader) {
    if(!show){

        // Mask on/off
        if(reflect){
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
            glStencilMask(0xFF);
        }  else{
            glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO);
            glStencilMask(0xFF);
        }
        shader->use();

        glm::mat4 m = glm::mat4(1.0f);
        m = glm::translate(m, position); // translate it down so it's at the center of the scene
        shader->setMat4("model", m);

        setTextures(shader);
        setLights(shader);

        this->texture_1->bind();
        this->texture_2->bind();

        this->vao->bind();

        glDrawArrays(GL_TRIANGLES, 0,6);

        this->vao->unbind();

        show = true;
        glStencilMask(0x00);
    }
}

void PlaneModel::remove() {
    this->vao->remove();
    this->vbo->remove();
}
