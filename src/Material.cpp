#include "Material.h"

Material::Material(std::string name) : name(name) {}

Material::Material(const std::string &name, const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular)
  : name(name), ambient(ambient), diffuse(diffuse), specular(specular) {}

std::string Material::getName() {
  return name;
}

float Material::getShininess() {
  return shininess;
}

float Material::getDissolve() {
  return dissolve;
}

float Material::getOpticalDensity() {
  return opticalDensity;
}

glm::vec3 Material::getAmbient() {
  return ambient;
}

glm::vec3 Material::getDiffuse() {
  return diffuse;
}

glm::vec3 Material::getSpecular() {
  return specular;
}

glm::vec3 Material::getEmissive() {
  return emissive;
}

int Material::getIllumination() {
  return illumination;
}

Material& Material::setName(const std::string &name) {
  this->name = name;
  return *this;
}

Material& Material::setShininess(const float shininess) {
  this->shininess = shininess;
  return *this;
}

Material& Material::setDissolve(const float dissolve) {
  this->dissolve = dissolve;
  return *this;
}

Material& Material::setOpticalDensity(const float opticalDensity) {
  this->opticalDensity = opticalDensity;
  return *this;
}

Material& Material::setAmbient(const glm::vec3 &ambient) {
  this->ambient = ambient;
  return *this;
}

Material& Material::setDiffuse(const glm::vec3 &diffuse) {
  this->diffuse = diffuse;
  return *this;
}

Material& Material::setSpecular(const glm::vec3 &specular) {
  this->specular = specular;
  return *this;
}

Material& Material::setEmissive(const glm::vec3 &emissive) {
  this->emissive = emissive;
  return *this;
}

Material& Material::setIllumination(const int illumination) {
  this->illumination = illumination;
  return *this;
}
