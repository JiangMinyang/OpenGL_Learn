#include "Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader() {}
Shader::~Shader() {}

void Shader::loadShader(const std::string &fileName, const GLuint &shaderType) {
  int index = 0;
  switch(shaderType) {
    case GL_VERTEX_SHADER:
      index = 0;
      break;
    case GL_FRAGMENT_SHADER:
      index = 1;
      break;
  }

  std::string content = loadFile(fileName);
  char* shaderContent = new char[content.size() + 1];
  std::copy(content.begin(), content.end(), shaderContent);
  shaderContent[content.size()] = '\0';

  shaders[index] = glCreateShader(shaderType);
  glShaderSource(shaders[index], 1, &shaderContent, NULL);
  glCompileShader(shaders[index]);

  std::string errorMessage = "ERROR WHEN COMPILING ";
  errorMessage += (shaderType == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");
  errorMessage += " SHADER";
  checkShaderError(shaders[index], GL_COMPILE_STATUS, false, errorMessage);
  delete[] shaderContent;
}

std::string Shader::loadFile(const std::string &fileName) {
  std::stringstream fileContent;
  std::ifstream file(fileName);

  std::string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      fileContent << line << std::endl;
    }
    return fileContent.str();
  } else {
    std::cerr << "Cannot load file " << fileName << std::endl; 
  }
  return NULL;
}

void Shader::linkShader() {
  program = glCreateProgram();
  for (int i = 0; i < NUM_SHADERS; i++) {
    if (shaders[i] != 0) {
      glAttachShader(program, shaders[i]);
    }
  }
  glLinkProgram(program);
  checkShaderError(program, GL_LINK_STATUS, true, "ERROR WHEN LINKING SHADERS");
  for (int i = 0; i < NUM_SHADERS; i++) {
    glDeleteShader(shaders[i]);
  }
}

void Shader::activate() {
  glUseProgram(program);
}


void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage) {
  GLint success;
  GLchar error[1024] = {0};
  if (isProgram) {
    glGetProgramiv(shader, flag, &success);
  } else {
    glGetShaderiv(shader, flag, &success);
  }
  if (success == GL_FALSE) {
    if (isProgram) {
      glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    } else {
      glGetShaderInfoLog(shader, sizeof(error), NULL, error);
    }
    std::cerr << errorMessage << ": " << error << std::endl;
  }
}