//
// Created by Lennert Steyaert on 19/03/2022.
//

#include<Model.h>

void Model::Draw(Shader &shader)
{
    for(unsigned int i = 0; i < meshes.size(); i++)
        meshes[i].Draw(shader);
}