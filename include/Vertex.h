#ifndef VERTEX_H
#define VERTEX_H

#include "glm/glm.hpp"

class Vertex {
public:
  Vertex(const glm::vec3& pos);
  Vertex(const glm::vec3& pos, const glm::vec2& texCoord);
  glm::vec3* getPosition();
  glm::vec2* getTextureCoord();
private:
  glm::vec3 position;
  glm::vec2 textureCoord;
};

#endif  // VERTEX_H