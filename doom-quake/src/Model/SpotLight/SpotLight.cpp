//
// Created by Lennert Steyaert on 11/05/2022.
//

#include "Model/SpotLight/SpotLight.h"


SpotLight::SpotLight(ShaderType type, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float constant, float linear, float quadratic, float cutOff, float outerCutOff) :
        BaseModel(type), ambient(ambient), diffuse(diffuse), specular(specular), constant(constant), linear(linear), quadratic(quadratic), cutOff(cutOff), outerCutOff(outerCutOff){
}



SpotLight::~SpotLight()  {
    std::cout << "deleted cubemodel" << std::endl;
}


void SpotLight::updatePosition(glm::vec3 pos){

}

void SpotLight::toggleSpotLight(bool state){
    this->state = state;
}

void SpotLight::setupShader(Shader * shader,uint &pos){
    if(state){

        shader->setBool("spotLightState", true);

        shader->setVec3("spotLight.ambient", ambient);
        shader->setVec3("spotLight.diffuse", diffuse);
        shader->setVec3("spotLight.specular", specular);
        shader->setFloat("spotLight.constant", constant);
        shader->setFloat("spotLight.linear", linear);
        shader->setFloat("spotLight.quadratic", quadratic);
        shader->setFloat("spotLight.cutOff", cutOff);
        shader->setFloat("spotLight.outerCutOff", outerCutOff);
    }
}

void SpotLight::draw(Shader *shader) {}

void SpotLight::remove() {}
