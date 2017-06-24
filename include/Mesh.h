#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <vector>
#include "Vertex.h"
#include "Face.h"

class Mesh {
public:
  Mesh(Vertex *vertex, unsigned int numVertices, Face *faces, unsigned int numFaces);
  Mesh(std::vector<Vertex> &vertices, unsigned int numVertices, std::vector<Face> faces, unsigned int numFaces);
  ~Mesh();
  void draw();
  void bind();
  void unbind();
private:
  static const int NUM_BUFFERS = 2;
  GLuint vertexArrayObject;
  GLuint vertexBufferObjects[NUM_BUFFERS];
  GLuint elementBufferObjects[NUM_BUFFERS];
  unsigned int drawCount;
};



#endif  //  MESH_H