//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_OCTREE_H
#define DOOM_QUAKE_OCTREE_H

#include "Node.h"
#include "Ray/Ray.h"
#include "Hit/Hit.h"

#include "Culling/Culling.h"

class Octree
{
public:
    Octree(BoundingBox& boundingBox, int depth);

    void addModel(BaseModel* model); // Add a model to the octree
    void shoot(Ray& ray, std::vector<std::unique_ptr<Hit>> & hitPoints); // Shooting function uses searchRecursive
    void draw(std::vector<std::unique_ptr<Shader>> & shaders, Culling * culling, bool octreeVisible);  // Draw method

private:
    std::unique_ptr<Node> root;

    void addModelRecursive(Node* node, BaseModel * model); // Recursive help method
    void generateChildren(Node* node);
    bool searchRecursive(Node* node, Ray& ray, std::vector<std::unique_ptr<Hit>>& hitPoints); // Fills hitpoints with ray collisions

    // This code comes from:
    // https://github.com/BSVino/MathForGameDevelopers/blob/line-box-intersection/math/collision.cpp
    bool intersect(BoundingBox& b1, Ray& ray);
    bool intersect(BoundingBox& b1, Ray& ray,glm::vec3 & vecIntersection, float & flFraction);
    bool clipLine(int d, BoundingBox &bb, const glm::vec3 &v0, const glm::vec3 &v1, float &f_low, float &f_high);
};

#endif //DOOM_QUAKE_OCTREE_H
