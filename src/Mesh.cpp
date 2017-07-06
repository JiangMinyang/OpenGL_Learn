#include "Mesh.h"
#include <GLFW/glfw3.h>
#include <vector>

Mesh::Mesh(const std::string& name) : name(name) {}

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices) {
  setup(vertices, indices);
}

void Mesh::setup(std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices) {
  drawCount = indices.size() * 3;

  glGenVertexArrays(1, &vertexArrayObject);
  glGenBuffers(NUM_BUFFERS, vertexBufferObjects);
  glGenBuffers(1, &elementBufferObjects);

  std::vector<glm::vec3> position;
  std::vector<glm::vec2> texture;
  std::vector<glm::vec3> normal;
  for(int i = 0; i < vertices.size(); i++) {
    position.push_back(*vertices[i].getPosition());
    if (vertices[i].getType() & 2) {
      texture.push_back(*vertices[i].getTexture());
    }
    if (vertices[i].getType() & 4) {
      normal.push_back(*vertices[i].getNormal());
    }
  }

  glBindVertexArray(vertexArrayObject);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects[0]);
  glBufferData(GL_ARRAY_BUFFER, position.size() * sizeof(position[0]), &position[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
  glEnableVertexAttribArray(0);

  if (texture.size() > 0) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects[1]);
    glBufferData(GL_ARRAY_BUFFER, texture.size() * sizeof(texture[0]), &texture[0], GL_STATIC_DRAW);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
  }

  if (normal.size() > 0) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects[2]);
    glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(normal[0]), &normal[0], GL_STATIC_DRAW);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(2);
  }

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObjects);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

  glBindVertexArray(0);
}

std::string Mesh::getName() {
  return name;
}

std::string Mesh::getMaterialName() {
  return materialName;
}

Mesh& Mesh::setName(const std::string &name) {
  this->name = name;
  return *this;
}

Mesh& Mesh::setMaterialName(const std::string &materialName) {
  this->materialName = materialName;
  return *this;
}

Mesh::~Mesh() {
  glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::bind() {
  glBindVertexArray(vertexArrayObject);
}

void Mesh::draw() {
  // glDrawArrays(GL_TRIANGLES, 0, drawCount);
  glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
}

void Mesh::unbind() {
  glBindVertexArray(0);
}
