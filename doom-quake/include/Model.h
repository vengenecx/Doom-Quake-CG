//
// Created by Lennert Steyaert on 19/03/2022.
//

#ifndef DOOM_QUAKE_MODEL_H
#define DOOM_QUAKE_MODEL_H

#include<Mesh.h>
#include <assimp/scene.h>

class Model
{
public:
    Model(char *path)
    {
        loadModel(path);
    }
    void Draw(Shader &shader);
private:
    // model data
    std::vector<Mesh> meshes;
    std::string directory;

    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                         std::string typeName);
};

#endif //DOOM_QUAKE_MODEL_H
