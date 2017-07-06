#include "Model.h"

Model::Model() {

}

void Model::draw() {

}

void Model::addMesh(const Mesh &mesh) {
  meshes.push_back(mesh);
}