//
// Created by Lepesh on 13.09.2024.
//

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(const glm::vec3 &direction, const glm::vec3 &color, float intensity) {
    Direction = direction;
    Color = color;
    Intensity = intensity;
}

const glm::vec3 &DirectionalLight::GetLightColor() const {
    return Color;
}

const float DirectionalLight::GetLightIntensity() const {
    return Intensity;
}

const glm::vec3 &DirectionalLight::GetLightDirection() const {
    return Direction;
}
