#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader {
public:
  Shader();
  ~Shader();
  void loadShader(const std::string &fileName, const GLuint &shaderType);
  void linkShader();
  void activate();
  GLuint getProgram();

private:
  static const unsigned int NUM_SHADERS = 2;
  GLuint shaders[NUM_SHADERS];
  GLuint program;

  void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);
  std::string loadFile(const std::string &fileName);
};

#endif  // SHADER_H