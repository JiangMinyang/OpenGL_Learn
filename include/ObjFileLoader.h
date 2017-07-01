#ifndef OBJ_FILE_LOADER_H
#define OBJ_FILE_LOADER_H

#include <string>
#include <vector>
#include "glm/glm.hpp"
#include "Vertex.h"

class ObjFileLoader {
public:
  static int loadFile(const char* filename, std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices);
};

#endif  //  OBJ_FILE_LOADER_H