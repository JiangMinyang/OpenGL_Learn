#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "Vertex.h"

class Mesh {
public:
  Mesh(Vertex *vertex, unsigned int numVertices);
  ~Mesh();
  void draw();
  void bind();
  void unbind();
private:
  static const int NUM_BUFFERS = 2;
  GLuint vertexArrayObject;
  GLuint vertexBufferObjects[NUM_BUFFERS];
  unsigned int drawCount;
};



#endif  //  MESH_H