#include <iostream>
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string &fileName) {
  Texture(fileName, GL_RGB);
}

Texture::Texture(const std::string &fileName, const GLuint imageDataType) {
  int width, height, channel;
  stbi_set_flip_vertically_on_load(true);
  unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &channel, 0);

  if (!imageData) {
    std::cout << "cannot load image " + fileName << std::endl;
  }
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, imageDataType, GL_UNSIGNED_BYTE, imageData);  
  stbi_image_free(imageData); 
}

Texture::~Texture() {
  glDeleteTextures(1, &texture);
}

void Texture::bind(const unsigned int unit) {
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, texture);
}