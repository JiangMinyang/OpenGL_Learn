#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <map>
#include <string>

#include "Mesh.h"
#include "Texture.h"

class Model {
public:
  Model();
  void draw();
private:
  std::sring modelName;
  std::vector<Mesh> meshes;
  std::vector<Texture> textures;
};

#endif  //  MODEL_H