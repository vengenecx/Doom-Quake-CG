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
        //Node* parent;

        Node(BoundingBox bb, int depth, bool draw=true);

        // Octant children
        std::unique_ptr<Node> children[OCTREE_CHILDREN];
//        // Only leafs contain a model
//        BaseModel* model;

        std::vector<BaseModel*> models;

        unsigned char activeOctants;

//        std::vector<Octants> matchChild(BoundingBox* bb);

    std::vector<Octants> matchChild(BoundingBox bb);
//        Node* getChild(Octants oc);

        BoundingBox boundingBox;

        bool hasChildren();

        bool depthEnd();

        int getDepth();


        void draw(std::vector<std::unique_ptr<Shader>> & shaders, Culling* culling, bool octreeVisible);

private:
    int depth;

    bool overlap(BoundingBox bb1, BoundingBox bb2);
    bool overlapPlane(BoundingBox bb1, BoundingBox bb2);

    bool fit(Culling* culling);

    void fillVertices(BoundingBox bx);

    bool fitBox(Culling* culling, BoundingBox bx);
    bool fitPlane(Culling* culling);
    bool fitAngle(Culling* culling);

    bool boxIn(BoundingBox bb1, BoundingBox bb2);

    bool drawState;

    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

//    std::unique_ptr<Texture> texture_1;
//    std::unique_ptr<Texture> texture_2;

    bool clipLine(int d, BoundingBox& bb,const glm::vec3& v0, const glm::vec3& v1, float& f_low, float& f_high);

    void drawBounds(std::vector<std::unique_ptr<Shader>> & shaders, bool octreeVisible);


    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    glm::vec3 position;

};
#endif //DOOM_QUAKE_NODE_H
