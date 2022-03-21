//
// Created by Lennert Steyaert on 19/03/2022.
//

#ifndef DOOM_QUAKE_MODEL_H
#define DOOM_QUAKE_MODEL_H

#include<Mesh.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <stb_image.h>

class Model
{
public:
    // constructor, expects a filepath to a 3D model.
    Model(std::string const &path, bool gamma = false) : gammaCorrection(gamma)
    {
        loadModel(path);
    }
    void Draw(Shader &shader);
private:
    // model data
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<Texture> textures_loaded;
    bool gammaCorrection;

    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                         std::string typeName);
    unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma= false);
};

#endif //DOOM_QUAKE_MODEL_H
