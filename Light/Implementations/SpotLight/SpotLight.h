//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_SPOTLIGHT_H
#define OPENGLPROJECT_SPOTLIGHT_H

#include<glm/glm.hpp>

struct SpotLight{
    glm::vec3 Position;
    glm::vec3 Direction;
    glm::vec3 Color;
    float Intensity;
    float InnerConeAngleCos;
    float OuterConeAngleCos;
};

#endif //OPENGLPROJECT_SPOTLIGHT_H
