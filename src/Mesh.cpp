#include "Mesh.h"
#include <GLFW/glfw3.h>

Mesh::Mesh(Vertex *vertices, unsigned int numVertices) : drawCount(numVertices) {
  glGenVertexArrays(1, &vertexArrayObject);
  glGenBuffers(1, &vertexBufferObject);

  glBindVertexArray(vertexArrayObject);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
  glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);

}
Mesh::~Mesh() {
  glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::draw() {
  glBindVertexArray(vertexArrayObject);
  
  glDrawArrays(GL_TRIANGLES, 0, drawCount);

  glBindVertexArray(0);
}