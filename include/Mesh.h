#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "Vertex.h"

class Mesh {
public:
  Mesh(Vertex *vertex, unsigned int numVertices);
  ~Mesh();
  void draw();
private:
  static const int NUM_BUFFERS = 1;
  GLuint vertexArrayObject;
  GLuint vertexBufferObject;
  unsigned int drawCount;
};



#endif  //  MESH_H