#include "Camera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include <iostream>
Camera::Camera() : Camera(glm::vec3(0.0, 0.0, 5.0), glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0)) {
  updateView();
}

Camera::Camera(const glm::vec3 cameraPosition, const glm::vec3 cameraFront, const glm::vec3 cameraUp) 
  : cameraPosition(cameraPosition), cameraFront(cameraFront), cameraUp(cameraUp) {
  updateView();
}

glm::mat4 Camera::getView() {
  std::cout << glm::to_string(viewMatrix) << std::endl;
  return viewMatrix;
}

void Camera::updateView() {
  viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

Camera& Camera::setCameraPosition(const glm::vec3 &cameraPosition) {
  this->cameraPosition = cameraPosition;
  updateView();
  return *this;
}
Camera& Camera::setCameraFront(const glm::vec3 &cameraFront) {
  this->cameraFront = cameraFront;
  updateView();
  return *this;
}
Camera& Camera::setCameraUp(const glm::vec3 &cameraUp) {
  this->cameraUp = cameraUp;
  updateView();
  return *this;
}