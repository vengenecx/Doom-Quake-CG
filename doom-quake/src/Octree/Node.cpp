//
// Created by Lennert Steyaert on 01/04/2022.
//

#include "Octree/Node.h"

Node::Node(BoundingBox bb, int depth, bool draw) : depth(depth), boundingBox(bb), drawState(draw){
    //TODO
    for(int i=0; i<8;i++){
        children[i] = NULL;
    }

    if(draw){

        this->vao = std::make_unique<VAO>();
        this->vao->bind();

        this->vertices = std::vector<float>();

//        std::cout<< "draw" << std::endl;
        fillVertices(bb);
        this->indices = std::vector<GLuint>
                {
                        0,1,2,3,4,5,6,7,
                        8,9,10,11,12,13,14,15,
                        16,17,18,19,20,21,22,23
                };

        this->vbo = std::make_unique<VBO>(vertices,vertices.size());
        this->ebo = std::make_unique<EBO>(indices,indices.size());



        vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
        vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

        //vao.linkAttrib(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

        // Unbind all to prevent accidentally modifying them
        vao->unbind();
        vbo->unbind();
        ebo->unbind();

//        this->position = bb.centre;
        this->position = glm::vec3(0,0,0);
    }
}


//std::vector<Octants> Node::matchChild(BoundingBox* bb)  {
std::vector<Octants> Node::matchChild(BoundingBox bb)  {
    // TODO
    std::vector<Octants> result = std::vector<Octants>();

    if(overlap(this->children[static_cast<int>(Octants::FRONTUPLEFT)]->boundingBox,bb))
        result.push_back(Octants::FRONTUPLEFT);

    if(overlap(this->children[static_cast<int>(Octants::FRONTUPRIGHT)]->boundingBox,bb))
        result.push_back(Octants::FRONTUPRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::FRONTBOTTOMRIGHT)]->boundingBox,bb))
        result.push_back(Octants::FRONTBOTTOMRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::FRONTBOTTOMLEFT)]->boundingBox,bb))
        result.push_back(Octants::FRONTBOTTOMLEFT);

    if(overlap(this->children[static_cast<int>(Octants::BACKUPLEFT)]->boundingBox,bb))
        result.push_back(Octants::BACKUPLEFT);

    if(overlap(this->children[static_cast<int>(Octants::BACKUPRIGHT)]->boundingBox,bb))
        result.push_back(Octants::BACKUPRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::BACKBOTTOMRIGHT)]->boundingBox,bb))
        result.push_back(Octants::BACKBOTTOMRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::BACKBOTTOMLEFT)]->boundingBox,bb))
        result.push_back(Octants::BACKBOTTOMLEFT);

    return result;
}

bool Node::overlap(BoundingBox bb1, BoundingBox bb2) {
    float min_x = bb1.centre.x - bb1.dimensions.x/2.0;
    float max_x = bb1.centre.x + bb1.dimensions.x/2.0;

    float min_y = bb1.centre.y - bb1.dimensions.y/2.0;
    float max_y = bb1.centre.y + bb1.dimensions.y/2.0;

    float min_z = bb1.centre.z - bb1.dimensions.z/2.0;
    float max_z = bb1.centre.z + bb1.dimensions.z/2.0;

    float min_x_bb2 = bb2.centre.x - bb2.dimensions.x/2.0;
    float max_x_bb2 = bb2.centre.x + bb2.dimensions.x/2.0;

    float min_y_bb2 = bb2.centre.y - bb2.dimensions.y/2.0;
    float max_y_bb2 = bb2.centre.y + bb2.dimensions.y/2.0;

    float min_z_bb2 = bb2.centre.z - bb2.dimensions.z/2.0;
    float max_z_bb2 = bb2.centre.z + bb2.dimensions.z/2.0;


    if(!(min_x_bb2 >= min_x && max_x > min_x_bb2 || min_x_bb2 <= min_x && max_x_bb2 > min_x))
        return false;
    if(!(min_y_bb2 >= min_y && max_y > min_y_bb2 || min_y_bb2 <= min_y && max_y_bb2 > min_y))
        return false;
    if(!(min_z_bb2 >= min_z && max_z > min_z_bb2 || min_z_bb2 <= min_z && max_z_bb2 > min_z))
        return false;

    return true;
}

bool Node::hasChildren() {
    return  children[0] != NULL ||
            children[1] != NULL ||
            children[2] != NULL ||
            children[3] != NULL ||
            children[4] != NULL ||
            children[5] != NULL ||
            children[6] != NULL ||
            children[7] != NULL;
}

bool Node::depthEnd() {
    return depth == 0;
}

int Node::getDepth() {
    return depth;
}


//bool Node::fit(Culling* culling){
//    float min_x = boundingBox.centre.x - boundingBox.dimensions.x/2;
//    float max_x = boundingBox.centre.x + boundingBox.dimensions.x/2;
//    float min_z = boundingBox.centre.z - boundingBox.dimensions.z/2;
//    float max_z = boundingBox.centre.z + boundingBox.dimensions.z/2;
//
//    glm::vec3 point = culling->getOrigin();
//    glm::vec3 left = culling->getRight();
//    glm::vec3 right = culling->getLeft();
//
//    float a1 = (min_z-point.z)/(left.z);
//    float a2 = (min_z-point.z)/(right.z);
//
//    float x1 = point.x + a1*left.x;
//    float x2 = point.x + a2*right.x;
//
//    float z1 = point.z + a2*left.z;
////    float z2 = point.z + a2*right.z;
//    float z2 = point.z;
//
//    if(x2 < x1)
//        std::swap(x1,x2);
//
//    if(z1 < z2)
//        std::swap(z1,z2);
//
//
//
////    if(min_x > x1 && x2 > max_x && min_x  < x2){
////        return true;
////    }
//
//    if(min_x > x1 && x2 > max_x && min_z > z1 && z2 > max_z ){
//        return true;
//    }
//
//    return false;
//}

bool Node::fit(Culling* culling){
    // vector

    glm::vec2 center_left = glm::vec2(boundingBox.centre.x- boundingBox.dimensions.x/2-culling->getOrigin().x,boundingBox.centre.z - boundingBox.dimensions.z/2-culling->getOrigin().z);
    glm::vec2 dir = glm::vec2(culling->getDirection().x,culling->getDirection().z);

    glm::vec2 da=glm::normalize(center_left);
    glm::vec2 db=glm::normalize(dir);
    float angle = glm::acos(glm::dot(da, db));

//    std::cout << angle*180/3.14 << std::endl;
    //return true;

    if(angle > -0.7853981634 && angle < 0.7853981634){
        float min_x = boundingBox.centre.x - boundingBox.dimensions.x/2;
        float max_x = boundingBox.centre.x + boundingBox.dimensions.x/2;
        float min_z = boundingBox.centre.z - boundingBox.dimensions.z/2;

       glm::vec3 point = culling->getOrigin();
        glm::vec3 left = culling->getRight();
        glm::vec3 right = culling->getLeft();
//
    float a1 = (min_z-point.z)/(left.z);
    float a2 = (min_z-point.z)/(right.z);

//
       float x1 = point.x + a1*left.x;
       float x2 = point.x + a2*right.x;

       if(x2 < x1)
           std::swap(x1,x2);


       if(min_x > x1 && x2 > max_x && min_x  < x2){
           return true;
       }


    } else{
        glm::vec2 center_right = glm::vec2(boundingBox.centre.x + boundingBox.dimensions.x/2 -culling->getOrigin().x,boundingBox.centre.z + boundingBox.dimensions.z/2-culling->getOrigin().z);


        da=glm::normalize(center_right);
        angle = glm::acos(glm::dot(da, db));

        if(angle > -0.7853981634 && angle < 0.7853981634){
            float min_x = boundingBox.centre.x - boundingBox.dimensions.x/2;
            float max_x = boundingBox.centre.x + boundingBox.dimensions.x/2;
            float min_z = boundingBox.centre.z - boundingBox.dimensions.z/2;

            glm::vec3 point = culling->getOrigin();
            glm::vec3 left = culling->getRight();
            glm::vec3 right = culling->getLeft();
//
            float a1 = (min_z-point.z)/(left.z);
            float a2 = (min_z-point.z)/(right.z);

//
            float x1 = point.x + a1*left.x;
            float x2 = point.x + a2*right.x;

            if(x2 < x1)
                std::swap(x1,x2);


            if(min_x > x1 && x2 > max_x && min_x  < x2){
                std::cout << "toch hier";
                return true;
            }

       }

    }

    return false;
}

bool Node::fitBox(Culling* culling, BoundingBox bx){
//    float min_x = bx.centre.x - bx.dimensions.x/2;
//    float max_x = bx.centre.x + bx.dimensions.x/2;
//    float min_z = bx.centre.z - bx.dimensions.z/2;
//    float max_z = bx.centre.z + bx.dimensions.z/2;
//
//    glm::vec3 point = culling->getOrigin();
//    glm::vec3 left = culling->getRight();
//    glm::vec3 right = culling->getLeft();
//
//    float a1 = (min_z-point.z)/(left.z);
//    float a2 = (min_z-point.z)/(right.z);
//
//    float x1 = point.x + a1*left.x;
//    float x2 = point.x + a2*right.x;
//
//    float z1 = point.z + a2*left.z;
////    float z2 = point.z + a2*right.z;
//
//    float z2 = point.z;
//
//    if(x2 < x1)
//        std::swap(x1,x2);
//
//    if(z1 < z2)
//        std::swap(z1,z2);
//
////    if(x2 < x1){
////        std::cout << "omgekeerd" << std::endl;
////    }
//
//    std::cout << "POS{ " << min_z << " , " << z1 << " }" << std::endl;
//
//    if(min_x > x1 && x2 > max_x ){
//        return true;
//    }
//
//    return false;

    glm::vec2 center_left = glm::vec2(bx.centre.x- bx.dimensions.x/2-culling->getOrigin().x,bx.centre.z - bx.dimensions.z/2-culling->getOrigin().z);
    glm::vec2 dir = glm::vec2(culling->getDirection().x,culling->getDirection().z);

    glm::vec2 da=glm::normalize(center_left);
    glm::vec2 db=glm::normalize(dir);
    float angle = glm::acos(glm::dot(da, db));

//    std::cout << angle*180/3.14 << std::endl;
    //return true;

    if(angle > -0.7853981634 && angle < 0.7853981634)
        return true;

    glm::vec2 center_right = glm::vec2(bx.centre.x + bx.dimensions.x/2 -culling->getOrigin().x,bx.centre.z + bx.dimensions.z/2-culling->getOrigin().z);


    da=glm::normalize(center_right);
    angle = glm::acos(glm::dot(da, db));

    if(angle > -0.7853981634 && angle < 0.7853981634)
        return true;

    return false;
}

void Node::draw(std::vector<std::unique_ptr<Shader>> & shaders, Culling* culling, bool octreeVisible){

    if(!hasChildren()){ // Leaf
        // check boundaries

        glm::vec2 center = glm::vec2(boundingBox.centre.x-culling->getOrigin().x,boundingBox.centre.z-culling->getOrigin().z);
        glm::vec2 dir = glm::vec2(culling->getDirection().x,culling->getDirection().z);

        glm::vec2 da=glm::normalize(center);
        glm::vec2 db=glm::normalize(dir);
        float angle = glm::acos(glm::dot(da, db));

//    std::cout << angle*180/3.14 << std::endl;
        //return true;

        if(angle > -0.7853981634 && angle < 0.7853981634){
            for(auto m : models){
                if(!m->shown()) {
                    if(fitBox(culling,m->getBoundingBox())) {
                        shaders[m->getShaderType()]->use();
                        if (m->getShaderType() == LIGHT) {
//                    std::cout << "lennert" << std::endl;
                            shaders[m->getShaderType()]->setVec3("viewPos", culling->getOrigin());
                        }
                        m->draw(shaders[m->getShaderType()].get());
                    }
                }
            }
            drawBounds(shaders, octreeVisible);
        }

    } else{
        if(fit(culling)){
            for(auto m : models){
                if(!m->shown()){
                    shaders[m->getShaderType()]->use();
                    if(m->getShaderType() == LIGHT){
                        shaders[m->getShaderType()]->setVec3("viewPos", culling->getOrigin());
                    }
                    m->draw(shaders[m->getShaderType()].get());
                }
            }
//            drawBounds(shaders, octreeVisible);
        } else{
            for(int i=0;  i<8; i++){
                if(children[i] != NULL)
                    children[i]->draw(shaders,culling, octreeVisible);
            }
        }
    }



    if(!hasChildren()){ // Leaf
//        for(auto m : models){
//            shaders[m->getShaderType()]->use();
//            m->draw(shaders[m->getShaderType()].get());
//        }
    }

//    for(auto m : models){
//        shaders[m->getShaderType()]->use();
//        m->draw(shaders[m->getShaderType()].get());
//    }

//    if(octreeVisible && drawState){
//        Shader* shader = shaders[LINE].get();
//        shader->use();
//
//        glm::mat4 m = glm::mat4(1.0f);
//        m = glm::translate(m, position); // translate it down so it's at the center of the scene
//        shader->setMat4("model", m);
//
//
//        this->vao->bind();
//        this->ebo->bind();
//
//        glDrawElements(GL_LINES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
//
//        this->vao->unbind();
//        this->ebo->unbind();
//    }

//    for(int i=0;  i<8; i++){
//        if(children[i] != NULL)
//            children[i]->draw(shaders,octreeVisible);
//    }
}


void Node::drawBounds(std::vector<std::unique_ptr<Shader>> & shaders, bool octreeVisible){
    if(octreeVisible){
        Shader* shader = shaders[LINE].get();
        shader->use();

        glm::mat4 m = glm::mat4(1.0f);
        m = glm::translate(m, position); // translate it down so it's at the center of the scene
        shader->setMat4("model", m);


        this->vao->bind();
        this->ebo->bind();

        glDrawElements(GL_LINES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);

        this->vao->unbind();
        this->ebo->unbind();
    }
}


void Node::fillVertices(BoundingBox bx){
    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    // Uper right to bottom front
    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);
//
//        // Bottom right front to left
    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    // Bottom left front to up left

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);


    // Added
    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);


    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);


    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);


    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);


    // Back

    // Upper left to right front
    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    // Uper right to bottom front
    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);
//
//        // Bottom right front to left
    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    // Bottom left front to up left

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(0.0);
    this->vertices.push_back(1.0);
    this->vertices.push_back(0.0);
}

//Node* Node::getChild(Octants oc){
//    // TODO
//    return nullptr;
//}

