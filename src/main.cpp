#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "window.h"
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
  glfwMakeContextCurrent(window.getWindow());

  while (!glfwWindowShouldClose(window.getWindow())) {
    glfwPollEvents();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window.getWindow());
  }

  glfwTerminate();
  return 0;
}
