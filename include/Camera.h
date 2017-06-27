#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Camera {
public:
  enum MOVEMENT_DIRECTION {
    FORWARD,
    BACKWORD,
    LEFT,
    RIGHT
  }
  static const float DEFAULT_YAW = -90;
  static const float DEFAULT_PITCH = 0;
  Camera(const glm::vec3 cameraPosition = glm::vec3(0.0, 0.0, 0.0), const glm::vec3 worldUp = glm::vec3(0.0, 1.0, 0.0), float yaw = DEFAULT_YAW, float pitch = DEFAULT_PITCH);
  glm::mat4 getView();
  Camera& setCameraPosition(const glm::vec3 &cameraPosition);
private:
  glm::vec3 cameraPosition;
  glm::vec3 cameraFront;
  glm::vec3 cameraUp;
  glm::vec3 cameraRight;
  glm::vec3 worldUp;
  float     yaw;
  float     pitch;
  void updateVectors();
};

#endif  //  CAMERA_H
