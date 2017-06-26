#include "Vertex.h"

Vertex::Vertex(const glm::vec3& pos) {
  this->position = pos;
  this->type = 1;
}

Vertex::Vertex(const glm::vec3& pos, const glm::vec2 &text) {
  this->position = pos;
  this->texture = text; 
  this->type = 3;
}

Vertex::Vertex(const glm::vec3& pos, const glm::vec2 &text, const glm::vec3 &normal) {
  this->position = pos;
  this->texture = text; 
  this->normal = normal;
  this->type = 7;
}

Vertex::Vertex(const glm::vec3& pos, const glm::vec3 &normal) {
  this->position = pos;
  this->normal = normal;
  this->type = 5;
}


Vertex::~Vertex() {
}

glm::vec3* Vertex::getPosition() {
  return &position;
}

glm::vec2* Vertex::getTexture() {
  return &texture;
}

glm::vec3* Vertex::getNormal() {
  return &normal;
}

short Vertex::getType() {
  return type;
}

