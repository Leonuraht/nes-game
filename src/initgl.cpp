#include "misc/initgl.hpp"
#include <iostream>

void error_callback(int code, const char *mssg) {
  std::cerr << "ERROR : " << code << " " << mssg << std::endl;
}

void resize_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

GLFWwindow *initialize() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwSetErrorCallback(error_callback);

  GLFWwindow *window =
      glfwCreateWindow(width, height, "_OpenGL_ Game", NULL, NULL);
  if (window == NULL) {
    std::cout << "ERROR : WINDOW CREATION FAILED" << std::endl;
    glfwTerminate();
    return NULL;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "ERROR : FAILED TO INITIALISE GLAD" << std::endl;
    return NULL;
  }
  glViewport(0, 0, width, height);
  glfwSetFramebufferSizeCallback(window, resize_callback);
  return window;
}
