//
// Created by Lepesh on 12.09.2024.
//

#include "ArcBallCamera.h"


ArcBallCamera::ArcBallCamera(float radius, float azimuth, float inclination, float rotationSpeed, float scaleSpeed) {
    Radius = radius;
    Azimuth = azimuth;
    Inclination = inclination;
    RotationSpeed = rotationSpeed;
    ScaleSpeed = scaleSpeed;
}

const glm::mat4 ArcBallCamera::GetViewMatrix() const {
    glm::vec3 eye = GetPosition();
    glm::vec3 target(0, 0, 0);
    glm::vec3 up(0, 1, 0);
    return glm::lookAt(eye, target, up);
}

const glm::vec3 ArcBallCamera::GetPosition() const {
    float theta = glm::radians(Azimuth);
    float phi = glm::radians(Inclination);

    float x = Radius * cos(phi) * cos(theta);
    float y = Radius * sin(phi);
    float z = Radius * cos(phi) * sin(theta);

    return {x, y, z};
}

void ArcBallCamera::Update(const CameraMouseInput &cmi, const CameraKeyboardInput &cki, float deltaTime) {
    ProcessMouseInput(cmi,deltaTime);
    ProcessKeyboardInput(cki,deltaTime);
}

void ArcBallCamera::ProcessMouseInput(const CameraMouseInput &cmi, float deltaTime) {
    Azimuth += RotationSpeed * cmi.mouseDeltaX * deltaTime;
    Inclination += RotationSpeed * cmi.mouseDeltaY * deltaTime;
    Radius += ScaleSpeed * deltaTime * cmi.mouseDeltaWheel;
    Inclination = std::max(-89.9f, std::min(89.9f, Inclination));
    Azimuth = fmod(Azimuth, 360.0f);
    Radius = std::max(0.1f, Radius);
}

void ArcBallCamera::ProcessKeyboardInput(const CameraKeyboardInput &cki, float deltaTime) {

}

ArcBallCamera::~ArcBallCamera() {

}
