#ifndef FACE_H
#define FACE_H

#include "glm/glm.hpp"

class Face {
public:
  Face(const glm::ivec3 &face);
  glm::ivec3 getFace();
private:
  glm::ivec3 face;
};

#endif  // FACE_H