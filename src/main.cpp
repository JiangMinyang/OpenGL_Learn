#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Texture.h"
const int WIDTH = 800;
const int HEIGHT = 600;

int main(void) {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  Window window(WIDTH, HEIGHT, "OpenGL");
  window.setAsCurrent();

  glewExperimental = GL_TRUE;
  glewInit();

  Shader shader;
  shader.loadShader("../resource/shader/basicShader.vert", GL_VERTEX_SHADER);
  shader.loadShader("../resource/shader/basicShader.frag", GL_FRAGMENT_SHADER);
  shader.linkShader();

  Texture texture("../resource/images/container.jpg", GL_RGB);
  Texture texture2("../resource/images/awesomeface.png", GL_RGBA);

  Vertex vertices[] = { Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0, 0.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.0, 1.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f,  0.5f, 0.0f), glm::vec2(1.0, 1.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.0, 1.0)) };

  Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

  shader.activate();
  glUniform1i(glGetUniformLocation(shader.getProgram(), "texture1"), 0);
  glUniform1i(glGetUniformLocation(shader.getProgram(), "texture2"), 1);

  while (!window.isClosed()) {

    shader.activate();

    window.clear(0.2f, 0.3f, 0.4f, 1.0f);
    texture.bind(0);
    texture2.bind(1);
    mesh.draw();

    window.update();
  }

  return 0;
}
