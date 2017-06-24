#include "Mesh.h"
#include <GLFW/glfw3.h>
#include <vector>

Mesh::Mesh(std::vector<Vertex> &vertices, unsigned int numVertices, std::vector<Face> faces, unsigned int numFaces) : drawCount(numFaces * 3) {
  glGenVertexArrays(1, &vertexArrayObject);
  glGenBuffers(NUM_BUFFERS, vertexBufferObjects);
  glGenBuffers(NUM_BUFFERS, elementBufferObjects);

  std::vector<glm::vec3> position;
  std::vector<glm::vec2> textureCoord;

  for(int i = 0; i < numVertices; i++) {
    position.push_back(*vertices[i].getPosition());
    // textureCoord.push_back(*vertices[i].getTextureCoord());
  }

  glBindVertexArray(vertexArrayObject);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects[0]);
  glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(position[0]), &position[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObjects[0]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, numFaces * sizeof(faces[0]), &faces[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

  glEnableVertexAttribArray(0);


  // glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects[1]);
  // glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(textureCoord[0]), &textureCoord[0], GL_STATIC_DRAW);

  // glEnableVertexAttribArray(1);
  // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

  glBindVertexArray(0);
}

Mesh::Mesh(Vertex *vertices, unsigned int numVertices, Face *faces, unsigned int numFaces) : drawCount(numFaces * 3) {
  glGenVertexArrays(1, &vertexArrayObject);
  glGenBuffers(NUM_BUFFERS, vertexBufferObjects);
  glGenBuffers(NUM_BUFFERS, elementBufferObjects);

  std::vector<glm::vec3> position;
  std::vector<glm::vec2> textureCoord;

  for(int i = 0; i < numVertices; i++) {
    position.push_back(*vertices[i].getPosition());
    // textureCoord.push_back(*vertices[i].getTextureCoord());
  }

  glBindVertexArray(vertexArrayObject);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects[0]);
  glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(position[0]), &position[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObjects[0]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, numFaces * sizeof(faces[0]), &faces[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

  glEnableVertexAttribArray(0);


  // glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects[1]);
  // glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(textureCoord[0]), &textureCoord[0], GL_STATIC_DRAW);

  // glEnableVertexAttribArray(1);
  // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

  glBindVertexArray(0);
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