//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_POINTLIGHT_H
#define OPENGLPROJECT_POINTLIGHT_H

#include<glm/glm.hpp>
#include "../Contracts/ILight/ILight.h"

class PointLight : public ILight{


private:
    glm::vec3 Position;
    glm::vec3 Color;
    float Intensity;
    glm::vec3 Attenuation; // x - Constant, y - Linear, z - Quadratic

public:

    const glm::vec3 &GetLightColor() const override;

    const float GetLightIntensity() const override;

    const glm::vec3& GetLightPosition() const;

    const glm::vec3& GetLightAttenuation() const;
};

#endif //OPENGLPROJECT_POINTLIGHT_H
