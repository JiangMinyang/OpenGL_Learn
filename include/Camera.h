#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Camera {
public:
  enum MOVEMENT_DIRECTION {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
  };
  static constexpr float DEFAULT_YAW = -90;
  static constexpr float DEFAULT_PITCH = 0;
  static constexpr float DEFAULT_ZOOM = 45;
  static constexpr float DEFAULT_SPEED = 3;
  static constexpr float DEFAULT_SENSITIVTY = 0.1;

  Camera(const glm::vec3 cameraPosition = glm::vec3(0.0, 0.0, 0.0), const glm::vec3 worldUp = glm::vec3(0.0, 1.0, 0.0), float yaw = DEFAULT_YAW, float pitch = DEFAULT_PITCH);
  glm::mat4 getView();
  glm::vec3 getPosition();
  float getZoom();
  Camera& setCameraPosition(const glm::vec3 &cameraPosition);
  void moveCamera(MOVEMENT_DIRECTION direction, float deltaTime);
  void rotateCamera(float x, float y);
  void zoomCamera(float delta);
private:
  const float PITCH_LIMIT = 89;
  const float ZOOM_UP_LIMIT = 70;
  const float ZOOM_LOWER_LIMIT = 1;
  glm::vec3 cameraPosition;
  glm::vec3 cameraFront;
  glm::vec3 cameraUp;
  glm::vec3 cameraRight;
  glm::vec3 worldUp;
  float     yaw;
  float     pitch;
  float     zoom;
  float     speed;
  float     sensitivity;
  void updateVectors();
};

#endif  //  CAMERA_H
