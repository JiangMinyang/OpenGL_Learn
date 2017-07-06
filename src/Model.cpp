#include "Model.h"
#include "Vertex.h"

Model::Model() {

}

void Model::draw() {

}

void Model::addMesh(const Mesh &mesh) {
  meshes[mesh.getName()] = mesh;
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
