//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_ICAMERA_H
#define OPENGLPROJECT_ICAMERA_H

#include <glm/glm.hpp>


struct CameraMouseInput{
    float mouseDeltaX;
    float mouseDeltaY;
    float mouseDeltaWheel;
};

struct CameraKeyboardInput{
    glm::vec3 dir;
};

class ICamera {

public:

    virtual const glm::mat4 GetViewMatrix() const = 0;

    virtual const glm::vec3 GetPosition() const = 0;

    virtual void Update(const CameraMouseInput& cmi, const CameraKeyboardInput& cki, float deltaTime) = 0;

    virtual ~ICamera() = default;

};


#endif //OPENGLPROJECT_ICAMERA_H
