//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_SPOTLIGHT_H
#define OPENGLPROJECT_SPOTLIGHT_H

#include<glm/glm.hpp>
#include "../../Contracts/ILight/ILight.h"

class SpotLight : public ILight{


private:
    glm::vec3 Position;
    glm::vec3 Direction;
    glm::vec3 Color;
    float Intensity;
    glm::vec2 ConesAngleCos; // x - Inner y - Outer

public:

    SpotLight(const glm::vec3& position, const glm::vec3& direction,
              const glm::vec3& color, const glm::vec2& conesAngleCos, float intensity);

    const glm::vec3 &GetLightColor() const override;

    const float GetLightIntensity() const override;

    const glm::vec3 &GetLightPosition() const;

    const glm::vec3 &GetLightDirection() const;

    const glm::vec2 &GetLightConesAngleCos() const;

};

#endif //OPENGLPROJECT_SPOTLIGHT_H
