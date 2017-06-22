#include "Vertex.h"

Vertex::Vertex(const glm::vec3& pos) : position(pos) {}
Vertex::Vertex(const glm::vec3& pos, const glm::vec2& textureCoord) : position(pos), textureCoord(textureCoord) {}

glm::vec3* Vertex::getPosition() {
  return &position;
}

glm::vec2* Vertex::getTextureCoord() {
  return &textureCoord;
}