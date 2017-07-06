#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <map>
#include <string>

#include "Mesh.h"
#include "Texture.h"
#include "Material.h"

class Model {
public:
  Model();
  void draw();
  void addMesh(const Mesh &mesh);
private:
  std::sring modelName;
  std::vector<Mesh> meshes;
  std::vector<Texture> textures;
  std::map<std::string, Material> materials;
};

#endif  //  MODEL_H