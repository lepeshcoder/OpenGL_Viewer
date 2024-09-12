//
// Created by Lepesh on 12.09.2024.
//

#include "FPSCamera.h"

FPSCamera::FPSCamera(const glm::vec3 &position, float yaw, float pitch,
                     float movementSpeed, float mouseSensitivity) {
    Position = position;
    Yaw = yaw;
    Pitch = pitch;
    MouseSensitivity = mouseSensitivity;
    MovementSpeed = movementSpeed;
    updateCameraVectors();
}

const glm::mat4 FPSCamera::GetViewMatrix() const {
    return glm::lookAt(Position, Position + Front, Up);
}

const glm::vec3 FPSCamera::GetPosition() const {
    return Position;
}

void FPSCamera::Update(const CameraMouseInput &cmi, const CameraKeyboardInput &cki, float deltaTime) {

    float velocity = MovementSpeed * deltaTime;

    glm::normalize(cki.dir);

    Position += velocity * cki.dir.x * Front;
    Position += velocity * cki.dir.y * Up;
    Position += velocity * cki.dir.z * Right;

    // Обработка ввода с мыши для вращения камеры
    Yaw += cmi.mouseDeltaX * MouseSensitivity;
    Pitch -= cmi.mouseDeltaY * MouseSensitivity;

    // Ограничение угла наклона, чтобы не переворачиваться
    if (Pitch > 89.9f) Pitch = 89.9f;
    if (Pitch < -89.9f) Pitch = -89.9f;
    Yaw = fmod(Yaw,360.0f);

    // Обновление векторов направления на основе новых углов
    updateCameraVectors();
}

void FPSCamera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);

    // Также обновляем Right и Up векторы
    Right = glm::normalize(glm::cross(Front, glm::vec3(0.0f, 1.0f, 0.0f))); // Вектор правого направления
    Up = glm::normalize(glm::cross(Right, Front));  // Вектор направления вверх
}




