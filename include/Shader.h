#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

#include "Material.h"

class Shader {
public:
  Shader();
  ~Shader();
  void loadShader(const std::string &fileName, const GLuint &shaderType);
  void linkShader();
  void activate() const;
  GLuint getProgram() const;
  void setInt(const std::string &name, const int &value) const;
  void setFloat(const std::string &name, const float &value) const;
  void setIntVector(const std::string &name, const glm::ivec3 &value) const;
  void setFloatVector(const std::string &name, const glm::vec3 &value) const;
  void setMatrix(const std::string &name, const glm::mat4 &value) const;
  void setMaterial(const std::string &name, const Material &material) const;

private:
  static const unsigned int NUM_SHADERS = 2;
  GLuint shaders[NUM_SHADERS];
  GLuint program;

  void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);
  std::string loadFile(const std::string &fileName);
};

#endif  // SHADER_H