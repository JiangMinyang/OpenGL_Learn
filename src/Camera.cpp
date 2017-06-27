#include "Camera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include <iostream>

Camera::Camera(const glm::vec3 cameraPosition, const glm::vec3 worldUp, float yaw, float pitch) {
  this->cameraPosition = cameraPosition;
  this->worldUp = worldUp;
  this->yaw = yaw;
  this->pitch = pitch;
  updateVectors();
}

glm::mat4 Camera::getView() {
  return glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

Camera& Camera::setCameraPosition(const glm::vec3 &cameraPosition) {
  this->cameraPosition = cameraPosition;
  return *this;
}

void Camera::updateVectors() {
  glm::vec3 front;
  front.x = cos(glm::radians(pitch)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(pitch)) * cos(glm::radians(yaw));
  cameraFront = glm::normalize(front);
}
