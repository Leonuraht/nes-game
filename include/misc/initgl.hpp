#ifndef INITGL_HPP
#define INITGL_HPP
#include "glad/glad.h"
#define GLAD_INCLUDE_NONE
#include "GLFW/glfw3.h"

/*
 *
 *        Provides Functions Used to initalise glfw & glad
 *
 *
 */

void error_callback(int code, const char *mssg);
void resize_callback(GLFWwindow *win, int width, int height);
void process_input(GLFWwindow *window);

#endif
