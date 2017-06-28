#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <string>
class Window {
public:
  Window();
  virtual ~Window();
  Window(const int &width, const int &height, const std::string &windowName);
  bool isClosed();
  void update();
  void setAsCurrent();
  void clear(const float &r, const float &g, const float &b, const float &a);

  GLFWwindow* getWindow();

private:
  GLuint WIDTH;
  GLuint HEIGHT;
  GLFWwindow *window;
};

#endif  // WINDOW_H
