#include "Model.h"
#include "Vertex.h"

Model::Model() {

}

void Model::draw() {
  for(std::map<std::string, Mesh>::iterator it = meshes.begin(); it != meshes.end(); ++it) {
    it->second.bind();
    it->second.draw();
    it->second.unbind();
  }
}

void Model::addMesh(const Mesh &mesh) {
  meshes[mesh.getName()] = mesh;
}

void Model::addMaterial(const Material &material) {
  materials[material.getName()] = material;
}

void Model::setupMesh(const std::string &meshName, std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices) {
  if (meshes.find(meshName) != meshes.end()) {
    meshes[meshName].setup(vertices, indices); 
  }
}

void Model::setMaterial(const std::string &meshName, const std::string &materialName) {
  if (meshes.find(meshName) != meshes.end()) {
    meshes[meshName].setMaterialName(materialName); 
  }
}
