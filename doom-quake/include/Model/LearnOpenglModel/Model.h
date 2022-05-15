//
// Created by Lennert Steyaert on 19/03/2022.
//

#ifndef DOOM_QUAKE_MODEL_H
#define DOOM_QUAKE_MODEL_H

#include "Mesh.h"
#include "assimp/scene.h"
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "stb_image.h"

#include "Octree/BoundingBox.h"
#include "Model/BaseModel.h"



// LearnOpengl!!!!!!
// https://learnopengl.com/Introduction

class Model : public BaseModel{
public:
    // constructor, expects a filepath to a 3D model.
    Model(std::string const &path, glm::vec3 position, glm::vec3 sizeOfScaling, glm::vec3 boundingBoxSize, ShaderType type,std::vector<BaseModel*> &light, bool gamma = false);
    ~Model();

    void draw(Shader *shader);
    void remove();
    void updatePosition(glm::vec3 pos);

    BoundingBox* getBoundingbox();

private:
    // model data
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<Texture> textures_loaded;
    bool gammaCorrection;

    glm::vec3 position;
    glm::vec3 sizeOfScaling;
    glm::vec3 boundingBoxSize;

    // TODO
    // Boundingbox calculation
    // https://www.sebastianhaas.at/calculating-bounding-box/
    std::unique_ptr<BoundingBox> boundingBox;
    void calculateBoundingBox();

    void setLights(Shader *shader);

    void drawReflection(Shader * shader);

    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                         std::string typeName);
    unsigned int textureFromFile(const char *path, const std::string &directory, bool gamma= false);
};

#endif //DOOM_QUAKE_MODEL_H
