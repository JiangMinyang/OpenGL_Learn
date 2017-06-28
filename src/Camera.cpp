#include "Camera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include <iostream>

Camera::Camera(const glm::vec3 cameraPosition, const glm::vec3 worldUp, float yaw, float pitch) {
  this->cameraPosition = cameraPosition;
  this->worldUp = worldUp;
  this->yaw = yaw;
  this->pitch = pitch;
  this->zoom = DEFAULT_ZOOM;
  this->speed = DEFAULT_SPEED;
  this->sensitivity = DEFAULT_SENSITIVTY;
  updateVectors();
}

glm::mat4 Camera::getView() {
  std::cout << glm::to_string(glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp)) << std::endl;
  return glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

float Camera::getZoom() {
  return zoom;
}

Camera& Camera::setCameraPosition(const glm::vec3 &cameraPosition) {
  this->cameraPosition = cameraPosition;
  return *this;
}

void Camera::moveCamera(MOVEMENT_DIRECTION direction, float deltaTime) {
  float distance = deltaTime * speed;
  switch (direction) {
    case FORWARD:
        cameraPosition += cameraFront * distance;
        break;
    case BACKWARD:
        cameraPosition -= cameraFront * distance;
        break;
    case LEFT:
        cameraPosition -= cameraRight * distance;
        break;
    case RIGHT:
        cameraPosition += cameraRight * distance;
        break;
  }
}

void Camera::rotateCamera(float x, float y) {
  pitch += y * sensitivity;
  yaw += x * sensitivity;
  if (pitch > PITCH_LIMIT) {
    pitch = PITCH_LIMIT;
  }
  if (pitch < -PITCH_LIMIT) {
    pitch = -PITCH_LIMIT;
  }
  updateVectors();
}

void Camera::zoomCamera(float delta) {
  zoom += delta;
  if (zoom > ZOOM_UP_LIMIT) {
    zoom = ZOOM_UP_LIMIT;
  }
  if (zoom < ZOOM_LOWER_LIMIT) {
    zoom = ZOOM_LOWER_LIMIT;
  }
}

void Camera::updateVectors() {
  glm::vec3 front;
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  cameraFront = glm::normalize(front);
  cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
  cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));

  std::cout << glm::to_string(cameraRight) << std::endl;
}
