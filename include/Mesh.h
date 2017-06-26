#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <vector>

#include "Vertex.h"

class Mesh {
public:
  Mesh(std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices);
  ~Mesh();
  void draw();
  void bind();
  void unbind();
private:
  static const int NUM_BUFFERS = 2;
  GLuint vertexArrayObject;
  GLuint vertexBufferObjects[NUM_BUFFERS];
  GLuint elementBufferObjects;
  unsigned int drawCount;
};



#endif  //  MESH_H