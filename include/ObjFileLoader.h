#ifndef OBJ_FILE_LOADER_H
#define OBJ_FILE_LOADER_H

#include <string>
#include <vector>
#include "glm/glm.hpp"
#include "Vertex.h"
#include "Model.h"

class ObjFileLoader {
public:
  static int loadObjectFile(const std::string& filename, Model &model);
  static int loadMaterialFile(const std::string& filename, Model &model);
};

#endif  //  OBJ_FILE_LOADER_H