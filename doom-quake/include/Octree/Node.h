//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_NODE_H
#define DOOM_QUAKE_NODE_H

#include <iostream>
#include "Octree/BoundingBox.h"
#include "Octants.h"
#include "Model/BaseModel.h"
#include "Culling/Culling.h"

#define OCTREE_CHILDREN 8

class Node
{
public:
    Node(BoundingBox bb, int depth);
    bool hasChildren();
    bool depthEnd();
    int getDepth();

    std::vector<Octants> matchChild(BoundingBox bb); // Return all childs which have overlap with the given bounding-box
    void draw(std::vector<std::unique_ptr<Shader>> & shaders, Culling* culling, bool octreeVisible);
    // TODO  something wrong
    void drawReflection(std::vector<std::unique_ptr<Shader>> & shaders, Culling* culling); // Reflection drawn

    // Dirty global variables
    BoundingBox boundingBox;
    // Each node can have 8 children
    std::unique_ptr<Node> children[OCTREE_CHILDREN];
    // All model(objects in paper)
    std::vector<BaseModel*> models;
private:
    int depth;
    glm::vec3 position;
    std::vector<float>  vertices;
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;


    bool overlap(BoundingBox bb1, BoundingBox bb2); // Calculate if overlap
    void fillVertices(BoundingBox bx); // Fill vertices vector
    bool boxIn(BoundingBox bb1, BoundingBox bb2); // Calculate of bb2 is in boundaries of bb1
    void drawBounds(std::vector<std::unique_ptr<Shader>> & shaders, bool octreeVisible); // Draw octree bounds
};
#endif //DOOM_QUAKE_NODE_H
