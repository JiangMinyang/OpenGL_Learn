#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Camera {
public:
  Camera();
  Camera(const glm::vec3 cameraPosition, const glm::vec3 cameraFront, const glm::vec3 cameraUp);
  glm::mat4 getView();
  Camera& setCameraPosition(const glm::vec3 &cameraPosition);
  Camera& setCameraFront(const glm::vec3 &cameraFront);
  Camera& setCameraUp(const glm::vec3 &cameraUp);
private:
  glm::vec3 cameraPosition;
  glm::vec3 cameraFront;
  glm::vec3 cameraUp;
  glm::mat4 viewMatrix;
  void updateView();
};

#endif  //  CAMERA_H
