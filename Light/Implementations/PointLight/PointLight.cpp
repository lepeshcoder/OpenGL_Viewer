//
// Created by Lepesh on 13.09.2024.
//
#include "PointLight.h"


const glm::vec3 &PointLight::GetLightColor() const {
    return Color;
}

const float PointLight::GetLightIntensity() const {
    return Intensity;
}

const glm::vec3 &PointLight::GetLightPosition() const {
    return Position;
}

const glm::vec3 &PointLight::GetLightAttenuation() const {
    return Attenuation;
}

