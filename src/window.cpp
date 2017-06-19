#include "Window.h"
#include <GLFW/glfw3.h>

Window::Window() {
  Window(800, 600, "hello");
}

Window::Window(const int &width, const int &height, const std::string &windowName) {
  WIDTH = width;
  HEIGHT = height;
  window = glfwCreateWindow(WIDTH, HEIGHT, windowName.c_str(), nullptr, nullptr);
}

Window::~Window() {
  glfwTerminate();
}

bool Window::isClosed() {
  return glfwWindowShouldClose(window);
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::setAsCurrent() {
  glfwMakeContextCurrent(window);
}

void Window::clear(const float &r, const float &g, const float &b, const float &a) {
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}