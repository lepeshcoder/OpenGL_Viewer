//
// Created by Lepesh on 13.09.2024.
//

#include "SpotLight.h"

SpotLight::SpotLight(const glm::vec3 &position, const glm::vec3 &direction, const glm::vec3 &color,
                     const glm::vec2 &conesAngleCos, float intensity) {
    Position = position;
    Direction = direction;
    Color = color;
    ConesAngleCos = conesAngleCos;
    Intensity = intensity;
}

const glm::vec3 &SpotLight::GetLightColor() const {
    return Color;
}

const float SpotLight::GetLightIntensity() const {
    return Intensity;
}

const glm::vec3 &SpotLight::GetLightPosition() const {
    return Position;
}

const glm::vec3 &SpotLight::GetLightDirection() const {
    return Direction;
}

const glm::vec2 &SpotLight::GetLightConesAngleCos() const {
    return ConesAngleCos;
}


