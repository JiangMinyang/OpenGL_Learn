#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Texture {
public:
  Texture(const std::string &fileName);
  Texture(const std::string &fileName, const GLuint imageDataType);
  void bind(const unsigned int unit);
  ~Texture();
private:
  GLuint texture;
};


#endif  //  TEXTURE_H