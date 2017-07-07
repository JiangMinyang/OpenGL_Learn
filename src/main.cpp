#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Window.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"
#include "ObjFileLoader.h"
#include "ResourceUtils.h"

const int WIDTH = 800;
const int HEIGHT = 600;

float lastX, lastY, lastTime;
bool firstMouse = true;
bool mouseClicked = false;
Camera camera(glm::vec3(0.0, 2.0, 20.0), glm::vec3(0.0, 1.0, 0));
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void processInput(GLFWwindow *window, float deltaTime);
int main(void) {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

//   glfwWindowHint(GLFW_SAMPLES, 4);

  Window window(WIDTH, HEIGHT, "OpenGL");
  window.setAsCurrent();

  glfwSetScrollCallback(window.getWindow(), scroll_callback);
  glfwSetCursorPosCallback(window.getWindow(), mouse_callback);

  glewExperimental = GL_TRUE;
  glewInit();

  Shader shader;
  shader.loadShader(ResourceUtils::getResourcePath("basicLightingShader.vert"), GL_VERTEX_SHADER);
  shader.loadShader(ResourceUtils::getResourcePath("basicLightingShader.frag"), GL_FRAGMENT_SHADER);
  shader.linkShader();

//   glEnable(GL_MULTISAMPLE);
  glEnable(GL_DEPTH_TEST);


//   Shader lightSource;
//   lightSource.loadShader("../resource/shader/lampLightSource.vert", GL_VERTEX_SHADER);
//   lightSource.loadShader("../resource/shader/lampLightSource.frag", GL_FRAGMENT_SHADER);
//   lightSource.linkShader();

  // Texture texture("../resource/images/container.jpg", GL_RGB);
  // Texture texture2("../resource/images/awesomeface.png", GL_RGBA);

  std::vector<Vertex> vertices = { Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)),
                                  Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0, 0.0), glm::vec3(0.0, 0.0, 1.0)), 
                                  Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0, 1.0), glm::vec3(0.0, 0.0, 1.0)),
                                  Vertex(glm::vec3(0.5f,  0.5f, 0.5f), glm::vec2(1.0, 1.0), glm::vec3(0.0, 0.0, 1.0)),

                                  Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0), glm::vec3(0.0, 0.0, -1.0)),
                                  Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0, 0.0), glm::vec3(0.0, 0.0, -1.0)),
                                  Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0, 1.0), glm::vec3(0.0, 0.0, -1.0)),
                                  Vertex(glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0, 1.0), glm::vec3(0.0, 0.0, -1.0)),

                                  Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0), glm::vec3(1.0, 0.0, 0.0)),
                                  Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0, 0.0), glm::vec3(1.0, 0.0, 0.0)),
                                  Vertex(glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(0.0, 1.0), glm::vec3(1.0, 0.0, 0.0)),
                                  Vertex(glm::vec3(0.5f,  0.5f, 0.5f), glm::vec2(1.0, 1.0), glm::vec3(1.0, 0.0, 0.0)),

                                  Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0, 0.0), glm::vec3(0.0, 1.0, 0.0)),
                                  Vertex(glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0, 0.0), glm::vec3(0.0, 1.0, 0.0)),
                                  Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0, 1.0), glm::vec3(0.0, 1.0, 0.0)),
                                  Vertex(glm::vec3(0.5f,  0.5f, 0.5f), glm::vec2(1.0, 1.0), glm::vec3(0.0, 1.0, 0.0)),

                                  Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(1.0, 0.0), glm::vec3(-1.0, 0.0, 0.0)),
                                  Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0, 1.0), glm::vec3(-1.0, 0.0, 0.0)),
                                  Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0, 1.0), glm::vec3(-1.0, 0.0, 0.0)),
                                  Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0), glm::vec3(-1.0, 0.0, 0.0)),

                                  Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)),
                                  Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)),
                                  Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)),
                                  Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0))};


  std::vector<glm::ivec3> vertexIndices = { glm::ivec3(0, 1, 2), glm::ivec3(2, 3, 1), glm::ivec3(4, 5, 6), glm::ivec3(6, 7, 5), glm::ivec3(8, 9, 10), glm::ivec3(10, 11, 9), 
                                      glm::ivec3(12, 13, 14), glm::ivec3(14, 15, 13), glm::ivec3(19, 16, 17), glm::ivec3(17, 18, 16), glm::ivec3(23, 20, 21), glm::ivec3(21, 22, 20) };
  vertices.clear();
  vertexIndices.clear();
  float start = glfwGetTime();
  // ObjFileLoader::loadFile("/Users/Minyang/Downloads/dragon.obj", vertices, vertexIndices);
  Model model;
  ObjFileLoader::loadObjectFile(ResourceUtils::getResourcePath("chess.obj"), model);

  glm::vec3 lightSourceLocation = glm::vec3(-3.0, 3.0, 3.0);
  glm::vec3 lightSourceDirection = glm::vec3(1.0, 1.0, 1.0);

  // Mesh mesh(vertices, vertexIndices);

  float deltaTime = 0.0;
  float lastFrame = 0.0;

  while (!window.isClosed()) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    processInput(window.getWindow(), deltaTime);

    shader.activate();

    window.clear(0.2f, 0.3f, 0.4f, 1.0f);

    glm::mat4 perspective;
    perspective = glm::perspective(glm::radians(camera.getZoom()), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
    
    glm::mat4 cameraRotate = camera.getView();
    // cameraRotate = glm::rotate(cameraRotate, (float)glfwGetTime(), glm::vec3(0.0, 1.0f, 0.0f));

    glm::mat4 transform;
    transform = glm::scale(transform, glm::vec3(1, 1, 1));
    glm::mat4 rotation;
    rotation = glm::rotate(rotation, (float)glfwGetTime(), glm::vec3(0.0, 1.0f, 0.0f)); 
    transform = transform * rotation;

    shader.setMatrix("transform", transform);
    shader.setMatrix("rotation", rotation);
    shader.setMatrix("model", perspective * cameraRotate);
    shader.setFloatVector("lightSource", lightSourceDirection);
    shader.setFloatVector("viewPosition", camera.getPosition());

    // mesh.bind();
    // mesh.draw();
    // mesh.unbind();
    model.draw(shader);

    window.update();
  }

  return 0;
}

void processInput(GLFWwindow *window, float deltaTime) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    camera.moveCamera(Camera::MOVEMENT_DIRECTION::FORWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    camera.moveCamera(Camera::MOVEMENT_DIRECTION::BACKWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    camera.moveCamera(Camera::MOVEMENT_DIRECTION::LEFT, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    camera.moveCamera(Camera::MOVEMENT_DIRECTION::RIGHT, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    camera.moveCamera(Camera::MOVEMENT_DIRECTION::UP, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    camera.moveCamera(Camera::MOVEMENT_DIRECTION::DOWN, deltaTime);
  if (glfwGetKey(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
    mouseClicked = true;
    firstMouse = true;
  }
  if (glfwGetKey(window, GLFW_MOUSE_BUTTON_1) == GLFW_RELEASE)
    mouseClicked = false;
  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
    mouseClicked = true;
  }
  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
    mouseClicked = false;
    firstMouse = true;
  }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
  camera.zoomCamera(yoffset);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
  if (!mouseClicked) return;
  if (firstMouse)
  {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

  lastX = xpos;
  lastY = ypos;
  lastTime = glfwGetTime();

  camera.rotateCamera(xoffset, yoffset);
}