//
// Created by Lennert Steyaert on 01/04/2022.
//

#include "Octree/Node.h"

Node::Node(BoundingBox bb, int depth) : depth(depth), boundingBox(bb){
    // Assign zero to all children pointers
    for(int i=0; i<8;i++){
        children[i] = NULL;
    }

    // Setup draw components for bounding-box
    this->vao = std::make_unique<VAO>();
    this->vao->bind();
    this->vertices = std::vector<float>();

    fillVertices(bb);

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());

    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    vao->unbind();
    vbo->unbind();
    vertices.clear(); // This can be more efficient
}

std::vector<Octants> Node::matchChild(BoundingBox bb)  {
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



bool Node::boxIn(BoundingBox bb1, BoundingBox bb2) {
    float min_x = bb1.centre.x - bb1.dimensions.x/2.0;
    float max_x = bb1.centre.x + bb1.dimensions.x/2.0;

    float min_z = bb1.centre.z - bb1.dimensions.z/2.0;
    float max_z = bb1.centre.z + bb1.dimensions.z/2.0;

    float min_x_bb2 = bb2.centre.x - bb2.dimensions.x/2.0;
    float max_x_bb2 = bb2.centre.x + bb2.dimensions.x/2.0;

    float min_z_bb2 = bb2.centre.z - bb2.dimensions.z/2.0;
    float max_z_bb2 = bb2.centre.z + bb2.dimensions.z/2.0;


    if(!(min_x_bb2 >= min_x && max_x >= max_x_bb2))
        return false;
    // Y check skipped (we didn't use any height elements)
    if(!(min_z_bb2 >= min_z && max_z >= max_z_bb2))
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

void Node::draw(std::vector<std::unique_ptr<Shader>> & shaders, Culling* culling, bool octreeVisible){

    if(!this->models.empty()){ // Check if  node contains any models
        // Node contains models

        BoundingBox cul = culling->getBounding(); // Fetch boundingbox (culling region)
        if(boxIn(cul,boundingBox)){ // Check if octree voxel is in culling region
            // All models in this not are drawn
            for(auto m : models){
                if(!m->shown()) {
                    shaders[m->getShaderType()]->use();
                    m->draw(shaders[m->getShaderType()].get());
                }
            }
            drawBounds(shaders, octreeVisible); // Boundaries of voxel
        } else{ // Octree voxel is not in culling region
            if(hasChildren()) {
                // Node has children which can be checked
                for(int i=0;  i<8; i++){
                    if(children[i] != NULL)
                        children[i]->draw(shaders,culling, octreeVisible);
                }
            } else{
                // Node is leaf, alle models are evaluated, when overlap -> model is drawn
                for(auto m : models){
                    if(!m->shown() && overlap(cul,m->getBoundingBox())) {
                        shaders[m->getShaderType()]->use();
                        m->draw(shaders[m->getShaderType()].get());
                    }
                }
                drawBounds(shaders, octreeVisible); // Boundaries of voxel
            }
        }
    }
}

// Dirty copy of the draw method
// Only drawReflection is called instead of draw
void Node::drawReflection(std::vector<std::unique_ptr<Shader>> & shaders, Culling* culling){
    if(!this->models.empty()){
        BoundingBox cul = culling->getBounding();
        if(boxIn(cul,boundingBox)){
            for(auto m : models){
                if(!m->shown()) {
                    shaders[m->getShaderType()]->use();
                    m->drawReflection(shaders[m->getShaderType()].get());
                }
            }
        } else{
            if(hasChildren()) {
                for(int i=0;  i<8; i++){
                    if(children[i] != NULL)
                        children[i]->drawReflection(shaders,culling);
                }
            } else{
                for(auto m : models){
                    if(!m->shown() && overlap(cul,m->getBoundingBox())) {
                        shaders[m->getShaderType()]->use();
                        m->drawReflection(shaders[m->getShaderType()].get());
                    }
                }
            }
        }
    }
}


void Node::drawBounds(std::vector<std::unique_ptr<Shader>> & shaders, bool octreeVisible){
    if(octreeVisible){
        Shader* shader = shaders[LINE].get();
        shader->use();

        glm::mat4 m = glm::mat4(1.0f);
        shader->setMat4("model", m);

        this->vao->bind();
        glDrawArrays(GL_LINES, 0, 24);
        this->vao->unbind();
    }
}

void Node::fillVertices(BoundingBox bx){

    static glm::vec3 color(0,1,0);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    // Uper right to bottom front
    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    // Bottom right front to left
    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    // Bottom left front to up left
    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    // Back

    // Upper left to right front
    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    // Uper right to bottom front
    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    // Bottom left front to up left
    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
    this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
    this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);
}

//bool Node::fitPlane(Culling* culling){
//
//    float min_x = boundingBox.centre.x - boundingBox.dimensions.x/2;
//    float max_x = boundingBox.centre.x + boundingBox.dimensions.x/2;
//    float min_z = boundingBox.centre.z - boundingBox.dimensions.z/2;
//
//    glm::vec3 point = culling->getOrigin();
//    glm::vec3 left = culling->getRight();
//    glm::vec3 right = culling->getLeft();
////
//    float a1 = (min_z-point.z)/(left.z);
//    float a2 = (min_z-point.z)/(right.z);
//
////
//   float x1 = point.x + a1*left.x;
//   float x2 = point.x + a2*right.x;
//
//   if(x2 < x1)
//       std::swap(x1,x2);
//
//    std::cout << "B1: " << min_x << " B2: " << max_x << std::endl;
//    std::cout << "x1: " << x1 << " x2: " << x2 << std::endl;
//
//   if(min_x > x1 && x2 > max_x)
//            return true;
//
//   return false;
//}
