#ifndef VERTEX_H
#define VERTEX_H

#include "glm/glm.hpp"

class Vertex {
public:
  Vertex(const glm::vec3& pos);
  Vertex(const glm::vec3& pos, const glm::vec2 &text);
  Vertex(const glm::vec3& pos, const glm::vec2 &text, const glm::vec3 &normal);
  Vertex(const glm::vec3& pos, const glm::vec3 &normal);
  ~Vertex();
  glm::vec3* getPosition();
  glm::vec2* getTexture();
  glm::vec3* getNormal();
  short getType();
private:
  glm::vec3 position;
  glm::vec2 texture;
  glm::vec3 normal;
  short type;
};

#endif  // VERTEX_H