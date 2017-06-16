#include "window.h"

Window::Window() {
  Window(800, 600, "hello");
}

Window::Window(const int &width, const int &height, const std::string &windowName) {
  this->WIDTH = width;
  this->HEIGHT = height;
  window = glfwCreateWindow(WIDTH, HEIGHT, windowName.c_str(), nullptr, nullptr);
}

GLFWwindow* Window::getWindow() {
  return this->window;
}