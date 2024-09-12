//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_FPSCAMERA_H
#define OPENGLPROJECT_FPSCAMERA_H


#include "../../Contracts/ICamera/ICamera.h"
#include <glm/gtc/matrix_transform.hpp>

class FPSCamera : public ICamera{

private:

    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    float Yaw;
    float Pitch;
    float MovementSpeed;
    float MouseSensitivity;

    void updateCameraVectors();

public:

    explicit FPSCamera(const glm::vec3& position = {0,0,0}, float yaw = 0, float pitch = 0,
              float movementSpeed = 1, float mouseSensitivity = 1);

    const glm::mat4 GetViewMatrix() const override;

    const glm::vec3 GetPosition() const override;

    void Update(const CameraMouseInput &cmi, const CameraKeyboardInput &cki, float deltaTime) override;

    ~FPSCamera() override = default;

};


#endif //OPENGLPROJECT_FPSCAMERA_H
