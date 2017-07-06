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
  void addMaterial(const Material &material);
  void setupMesh(const std::string &meshName, std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices);
  void setMaterial(const std::string &meshName, const std::string &materialName);
private:
  std::string modelName;
  std::map<std::string, Mesh> meshes;
  std::vector<Texture> textures;
  std::map<std::string, Material> materials;
};

#endif  //  MODEL_H