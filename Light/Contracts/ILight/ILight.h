//
// Created by Lepesh on 13.09.2024.
//

#ifndef OPENGLPROJECT_ILIGHT_H
#define OPENGLPROJECT_ILIGHT_H

#include <glm/glm.hpp>

class ILight {

public:
    virtual const glm::vec3& GetLightColor() const = 0;

    virtual const float GetLightIntensity() const = 0;

    virtual ~ILight() = default;
};


#endif //OPENGLPROJECT_ILIGHT_H
