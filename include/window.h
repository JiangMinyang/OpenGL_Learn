#include <GLFW/glfw3.h>
#include <string>
class Window {
private:
  GLuint WIDTH;
  GLuint HEIGHT;
  GLFWwindow *window;

public:
  Window();
  Window(const int &width, const int &height, const std::string &windowName);
  GLFWwindow* getWindow();
};