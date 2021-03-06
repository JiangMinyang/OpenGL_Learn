#ifndef MATERIAL_H
#define MATERIAL_H
#include "glm/glm.hpp"
#include <string>
class Material {
public:
  Material();
  Material(const std::string &name);
  Material(const std::string &name, const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular);
  std::string getName() const;
  float getShininess() const;
  float getDissolve() const;
  float getOpticalDensity() const;
  glm::vec3 getAmbient() const;
  glm::vec3 getDiffuse() const;
  glm::vec3 getSpecular() const;
  glm::vec3 getEmissive() const;
  int getIllumination() const;
  Material& setName(const std::string &name);
  Material& setShininess(const float shininess);
  Material& setDissolve(const float dissolve);
  Material& setOpticalDensity(const float opticalDensity);
  Material& setAmbient(const glm::vec3 &ambient);
  Material& setDiffuse(const glm::vec3 &diffuse);
  Material& setSpecular(const glm::vec3 &specular);
  Material& setEmissive(const glm::vec3 &emissive);
  Material& setIllumination(const int illumination);
private:
  std::string name;
  float shininess;
  float dissolve;
  float opticalDensity;
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  glm::vec3 emissive;
  int illumination;
};

#endif  //  MATERIAL_H