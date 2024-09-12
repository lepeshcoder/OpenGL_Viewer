//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_ARCBALLCAMERA_H
#define OPENGLPROJECT_ARCBALLCAMERA_H


#include "../../Contracts/ICamera/ICamera.h"
#include <glm/gtc/matrix_transform.hpp>

class ArcBallCamera : public ICamera {

private:

    float Radius, Azimuth, Inclination;
    float ScaleSpeed, RotationSpeed;

    void ProcessMouseInput(const CameraMouseInput& cmi, float deltaTime);
    void ProcessKeyboardInput(const CameraKeyboardInput& cki, float deltaTime);

public:

    explicit ArcBallCamera(float radius = 10.0f ,float azimuth = 0.0f, float inclination = 0.0f,
                  float rotationSpeed = 1.0f, float scaleSpeed = 1.0f );

    const glm::mat4 GetViewMatrix() const override;

    const glm::vec3 GetPosition() const override;

    void Update(const CameraMouseInput& cmi, const CameraKeyboardInput& cki, float deltaTime) override;

    ~ArcBallCamera() override;

};


#endif //OPENGLPROJECT_ARCBALLCAMERA_H
