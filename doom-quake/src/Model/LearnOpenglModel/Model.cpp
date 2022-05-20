//
// Created by Lennert Steyaert on 19/03/2022.
//

// following code was written with help of the following URL: https://learnopengl.com/Model-Loading/Model


#include"Model/LearnOpenglModel/Model.h"


Model::Model(std::string const &path, glm::vec3 position, glm::vec3 sizeOfScaling, glm::vec3 boundingBoxSize, ShaderType type,std::vector<BaseModel*> &light, bool gamma) : BaseModel(type, light), position(position), sizeOfScaling(sizeOfScaling), boundingBoxSize(boundingBoxSize),gammaCorrection(gamma)
{
    loadModel(path);
    this->bb = BoundingBox();
    this->bb.centre = position;
    this->bb.dimensions  =  boundingBoxSize;
}


Model::~Model(){
    boundingBox.release();
}

void Model::remove(){
    for(auto& m : meshes){
        m.remove();
    }
}

void Model::updatePosition(glm::vec3 pos){
    this->position = pos;
}


void Model::setLights(Shader* shader) {

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


void Model::draw(Shader *shader)
{
    // render the loaded model
    glm::mat4 m = glm::mat4(1.0f);
    //m = glm::translate(m, glm::vec3(0.0f, 0.0f, -20.0f)); // translate it down so it's at the center of the scene

    m = glm::translate(m, position);

    m = glm::scale(m, sizeOfScaling);	// it's a bit too big for our scene, so scale it down

    shader->setMat4("model", m);

    setLights(shader);


    for(unsigned int i = 0; i < meshes.size(); i++)
        meshes[i].draw(shader);


    show = true;
}

void Model::drawReflection(Shader * shader){
    if(gammaCorrection){
        std::cout << ".";
        // render the loaded model
        glm::mat4 m = glm::mat4(1.0f);
        //m = glm::translate(m, glm::vec3(0.0f, 0.0f, -20.0f)); // translate it down so it's at the center of the scene

        glm::vec3 reflecPos = glm::vec3(position.x,-1.5,position.z);

        m = glm::rotate(m, glm::radians(-1.1415926536f), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
        m = glm::translate(m, reflecPos);


        m = glm::scale(m, sizeOfScaling);	// it's a bit too big for our scene, so scale it down




        shader->setMat4("model", m);

        shader->setFloat("material.shininess", 100.0f);
        shader->setBool("pointLightState", false);
        shader->setBool("spotLightState", false);


        shader->setBool("directionLightState", true);
        shader->setVec3("dirLight.position", position);
        shader->setVec3("dirLight.ambient", glm::vec3(0.05,0.05,0.05));
        shader->setVec3("dirLight.diffuse", glm::vec3(0.3,0.3,0.3));
        shader->setVec3("dirLight.specular", glm::vec3(0.1,0.1,0.1));



        for(unsigned int i = 0; i < meshes.size(); i++)
            meshes[i].draw(shader);


        show = true;
    }
}

BoundingBox* Model::getBoundingbox(){
    // TODO
    return boundingBox.get();
}

void Model::calculateBoundingBox(){
    // TODO
}

void Model::loadModel(std::string path)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    // process all the node's meshes (if any)
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    // then do the same for each of its children
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    // data to fill
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    // walk through each of the mesh's vertices
    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        glm::vec3 vector; // we declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
        // positions
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.Position = vector;
        // normals
        if (mesh->HasNormals())
        {
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.Normal = vector;
        }

        // texture coordinates
        if(mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            //std::cout << "normal" << std::endl;
            glm::vec2 vec;
            // a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't
            // use models where a vertex can have multiple texture coordinates so we always take the first set (0).
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = vec;
            // tangent
            vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            vertex.Tangent = vector;
            // bitangent
            vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            vertex.Bitangent = vector;
        }
        else
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);

        vertices.push_back(vertex);
    }
    // now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        // retrieve all indices of the face and store them in the indices vector
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }
    // process materials
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
    // we assume a convention for sampler names in the shaders. Each diffuse texture should be named
    // as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER.
    // Same applies to other texture as the following list summarizes:
    // diffuse: texture_diffuseN
    // specular: texture_specularN
    // normal: texture_normalN

//    // 1. diffuse maps
//    std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
//    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
//    // 2. specular maps
//    std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
//    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
//    // 3. normal maps
//    std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
//    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
//    // 4. height maps
//    std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
//    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    // 1. diffuse maps
    std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "material.diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    // 2. specular maps
//    std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "material.specular");
//    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
//    // 3. normal maps
    std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "material.specular");
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
//    // 4. height maps
//    std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
//    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    // return a mesh object created from the extracted mesh data
    return Mesh(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
{
    std::vector<Texture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for(unsigned int j = 0; j < textures_loaded.size(); j++)
        {
            if(std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
            {
                textures.push_back(textures_loaded[j]);
                skip = true;
                break;
            }
        }
        if(!skip)
        {   // if texture hasn't been loaded already, load it
            Texture texture;
            texture.ID = textureFromFile(str.C_Str(), directory);
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
            textures_loaded.push_back(texture); // add to loaded textures
        }
    }
    return textures;
}

unsigned int Model::textureFromFile(const char *path, const std::string &directory, bool gamma)
{
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }
    return textureID;
}

