#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <vector>
#include <string>

#include "Vertex.h"

class Mesh {
public:
  Mesh(std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices);
  Mesh(const std::string &name);
  ~Mesh();
  void setup(std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices);
  std::string getName();
  std::string getMaterialName();
  Mesh& setName(const std::string &name);
  Mesh& setMaterialName(const std::string &materialName);
  
  void draw();
  void bind();
  void unbind();
private:
  static const int NUM_BUFFERS = 3;
  std::string name;
  std::string materialName;
  GLuint vertexArrayObject;
  GLuint vertexBufferObjects[NUM_BUFFERS];
  GLuint elementBufferObjects;
  unsigned int drawCount;
};



#endif  //  MESH_H