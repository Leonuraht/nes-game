#ifndef INITGL_HPP
#define INITGL_HPP
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

/*
 *
 *        Provides Functions Used to initalise glfw & glad
 *
 *
 */

const int width = 800;
const int height = 600;

void error_callback(int code, const char *mssg);
void resize_callback(GLFWwindow *win, int width, int height);
void process_input(GLFWwindow *window);
GLFWwindow *initialize();

#endif
