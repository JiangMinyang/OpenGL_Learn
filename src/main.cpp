#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
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

  Vertex vertices[] = { Vertex(glm::vec3(-0.5f, -0.5f, 0.0f)),
                        Vertex(glm::vec3(0.5f, -0.5f, 0.0f)),
                        Vertex(glm::vec3(0.0f,  0.5f, 0.0f)) };

  Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

  while (!window.isClosed()) {

    shader.activate();

    window.clear(0.2f, 0.3f, 0.4f, 1.0f);

    mesh.draw();

    window.update();
  }

  return 0;
}
