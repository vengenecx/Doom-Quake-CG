//
// Created by Lennert Steyaert on 11/05/2022.
//

#ifndef DOOM_QUAKE_SPOTLIGHT_H
#define DOOM_QUAKE_SPOTLIGHT_H

#include "Model/BaseModel.h"

class SpotLight : public BaseModel {
public:
    SpotLight(ShaderType type, glm::vec3 ambient = glm::vec3(0.0,0.0,0.0),glm::vec3 diffuse = glm::vec3(0.6,0.6,0.6), glm::vec3 specular = glm::vec3(0.2,0.2,0.2), float constant = 1.0f, float linear = 0.09f,  float quadratic = 0.032f,  float cutOff = glm::cos(glm::radians(12.5f)), float outerCutOff = glm::cos(glm::radians(15.0f)));

    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    void setupShader(Shader * shader,uint &pos);

    void toggleSpotLight(bool state);

    ~SpotLight();
private:

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float constant;
    float linear;
    float quadratic;
    float cutOff;
    float outerCutOff;

    bool state = true;

    void setTextures(Shader* shader);
};

#endif //DOOM_QUAKE_SPOTLIGHT_H
