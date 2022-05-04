//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_OCTREE_H
#define DOOM_QUAKE_OCTREE_H

#include "Node.h"
#include "Ray/Ray.h"
#include "NodeCluster.h"
#include "Hit/Hit.h"

class Octree
{
public:
    Octree(BoundingBox& boundingBox, int depth);

    void addModel(BaseModel* model);


    bool query(Ray & ray);

    std::unique_ptr<NodeCluster> query(BoundingBox& b);

    void shoot(Ray& ray, std::vector<std::unique_ptr<Hit>> & hitPoints);

    bool searchRecursive(Node* node, Ray& ray, std::vector<std::unique_ptr<Hit>>& hitPoints);


    void draw(Shader* shader);



private:
    std::unique_ptr<Node> root;

    bool containsBoundaries(Node * node, BoundingBox* boundingBox);
    void generateChildren(Node* node);
    void assignCurrentModelToChildren(Node* node);


    bool intersect(BoundingBox& b1, Ray& ray);

    bool intersect(BoundingBox& b1, Ray& ray,glm::vec3 & vecIntersection, float & flFraction);


    void addModelRecursive(Node* node, BaseModel * model);

    bool clipLine(int d, BoundingBox &bb, const glm::vec3 &v0, const glm::vec3 &v1, float &f_low, float &f_high);
};

#endif //DOOM_QUAKE_OCTREE_H
