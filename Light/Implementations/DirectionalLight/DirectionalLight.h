//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_DIRECTIONALLIGHT_H
#define OPENGLPROJECT_DIRECTIONALLIGHT_H

#include<glm/glm.hpp>
#include "../Contracts/ILight/ILight.h"

class DirectionalLight : public ILight{

private:
    glm::vec3 Direction;
    glm::vec3 Color;
    float Intensity;

public:

    DirectionalLight(const glm::vec3& direction, const glm::vec3& color, float intensity);

private:
    const glm::vec3 &GetLightColor() const override;

    const float GetLightIntensity() const override;

    const glm::vec3& GetLightDirection() const;
};

#endif //OPENGLPROJECT_DIRECTIONALLIGHT_H
