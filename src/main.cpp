#include "misc/initgl.hpp"
#include <iostream>

const int width = 800;
const int height = 600;

float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwSetErrorCallback(error_callback);

  GLFWwindow *window =
      glfwCreateWindow(width, height, "_OpenGL_ Game", NULL, NULL);
  if (window == NULL) {
    std::cout << "ERROR : WINDOW CREATION FAILED\n" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "ERROR : FAILED TO INITIALISE GLAD" << std::endl;
    return -1;
  }
  glViewport(0, 0, width, height);
  glfwSetFramebufferSizeCallback(window, resize_callback);

  unsigned int VAO, VBO;
  glCreateVertexArrays(1, &VAO);
  glCreateBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  while (!glfwWindowShouldClose(window)) {
    process_input(window);
    glClearColor(0.2f, 0.3f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
