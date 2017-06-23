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

  Vertex vertices[] = { Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0, 0.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0, 1.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f,  0.5f, 0.5f), glm::vec2(1.0, 1.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0, 1.0)),

                        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0, 1.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0, 1.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0, 1.0)),

                        Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0, 1.0)),
                        Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f,  0.5f, 0.5f), glm::vec2(1.0, 1.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0, 1.0)),

                        Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0, 0.0)),
                        Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(0.0, 1.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f,  0.5f, 0.5f), glm::vec2(1.0, 1.0)),
                        Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(0.0, 1.0)),

                        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0)),
                        Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0, 1.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(-0.5f,  0.5f, 0.5f), glm::vec2(1.0, 1.0)),
                        Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0, 1.0)),

                        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0, 0.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0, 1.0)),
                        Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(1.0, 0.0)),
                        Vertex(glm::vec3(0.5f,  -0.5f, 0.5f), glm::vec2(1.0, 1.0)),
                        Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0, 1.0)) };

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

  Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
  glEnable(GL_DEPTH_TEST);
  shader.activate();
  glUniform1i(glGetUniformLocation(shader.getProgram(), "texture1"), 0);
  glUniform1i(glGetUniformLocation(shader.getProgram(), "texture2"), 1);

  while (!window.isClosed()) {

    shader.activate();

    window.clear(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    texture.bind(0);
    texture2.bind(1);

    glm::mat4 view;
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(70.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
    view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
    view       = glm::rotate(view, (float)glfwGetTime(), glm::vec3(0, 1, 0));
    unsigned int projectionLoc = glGetUniformLocation(shader.getProgram(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
    unsigned int viewLoc = glGetUniformLocation(shader.getProgram(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    // glm::mat4 transform;
    // transform = glm::scale(transform, glm::vec3(0.5, 0.5, 0.5));
    // transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f)); 
    // unsigned int transformLoc = glGetUniformLocation(shader.getProgram(), "transform");
    // glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

    // mesh.draw();
    mesh.bind();
    for (unsigned int i = 0; i < 10; i++) {
      // calculate the model matrix for each object and pass it to shader before drawing
      glm::mat4 model;
      model = glm::translate(model, cubePositions[i]);
      float angle = 20.0f * i;
      model = glm::rotate(model, glm::radians(angle) + (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
      unsigned int transformLoc = glGetUniformLocation(shader.getProgram(), "transform");
      glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));

      // glDrawArrays(GL_TRIANGLES, 0, 36);
      mesh.draw();
    }
    // mesh.draw();

    mesh.unbind();

    window.update();
  }

  return 0;
}
