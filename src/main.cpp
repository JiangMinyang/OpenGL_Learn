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

const int WIDTH = 800;
const int HEIGHT = 600;

Camera camera(glm::vec3(0.0, 0.0, 3.0), glm::vec3(0.0, 1.0, 0));
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void processInput(GLFWwindow *window, float deltaTime);
int main(void) {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  Window window(WIDTH, HEIGHT, "OpenGL");
  window.setAsCurrent();

  glfwSetScrollCallback(window.getWindow(), scroll_callback);

  glewExperimental = GL_TRUE;
  glewInit();

  Shader shader1;
  shader1.loadShader("../resource/shader/basicShader.vert", GL_VERTEX_SHADER);
  shader1.loadShader("../resource/shader/basicShader.frag", GL_FRAGMENT_SHADER);
  shader1.linkShader();

  // Shader lightSource;
  // lightSource.loadShader("../resource/shader/lampLightSource.vert", GL_VERTEX_SHADER);
  // lightSource.loadShader("../resource/shader/lampLightSource.frag", GL_FRAGMENT_SHADER);
  // lightSource.linkShader();

  Texture texture("../resource/images/container.jpg", GL_RGB);
  Texture texture2("../resource/images/awesomeface.png", GL_RGBA);

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

  glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

  Mesh mesh(vertices, vertexIndices);
  glEnable(GL_DEPTH_TEST);
  shader1.activate();
  shader1.setInt("texture1", 0);
  shader1.setInt("texture2", 1);



  // Camera camera;
  // camera.setCameraPosition(glm::vec3(0.0, 0.0, 3.0)).setCameraFront(glm::vec3(0.0, 0.0, -1.0)).setCameraUp(glm::vec3(0.0, 1.0, 0.0));
  // camera.setCameraPosition(glm::vec3(-3.0, 0.0, 0.0)).setCameraFront(glm::vec3(1, 0, 0));

  float deltaTime = 0.0;
  float lastFrame = 0.0;

  while (!window.isClosed()) {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    processInput(window.getWindow(), deltaTime);

    shader1.activate();
    // lightSource.activate();

    window.clear(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    texture.bind(0);
    texture2.bind(1);

    // glm::mat4 view;
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(camera.getZoom()), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
    // view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
    // view       = glm::rotate(view, (float)glfwGetTime(), glm::vec3(0, 1, 0));
    // unsigned int projectionLoc = glGetUniformLocation(shader.getProgram(), "projection");
    // glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
    // unsigned int viewLoc = glGetUniformLocation(shader.getProgram(), "view");
    // glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    
    shader1.setMatrix("model", projection * camera.getView());

    glm::mat4 transform;
    transform = glm::scale(transform, glm::vec3(0.5, 0.5, 0.5));
    transform = glm::rotate(transform, (float)glfwGetTime() * 2, glm::vec3(0.5f, 1.0f, 0.0f)); 
    shader1.setMatrix("transform", transform);

    // mesh.draw();
    mesh.bind();
    // for (unsigned int i = 0; i < 10; i++) {
    //   // calculate the model matrix for each object and pass it to shader before drawing
    //   glm::mat4 model;
    //   model = glm::translate(model, cubePositions[i]);
    //   model = glm::translate(model, glm::vec3(0, 0, 3));
    //   float angle = 20.0f * i;
    //   model = glm::rotate(model, glm::radians(angle) + (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
    //   unsigned int transformLoc = glGetUniformLocation(shader.getProgram(), "transform");
    //   glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));

    //   // glDrawArrays(GL_TRIANGLES, 0, 36);
    //   mesh.draw();
    // }
    mesh.draw();

    mesh.unbind();

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
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
  camera.zoomCamera(yoffset);
}