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
