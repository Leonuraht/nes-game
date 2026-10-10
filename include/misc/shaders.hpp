#ifndef SHADER_HPP
#define SHADER_HPP
#include "glad/glad.h"
#define GLAD_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <iostream>

/*
 *
 *        Provides Functions Used to create and read shaders.
 *
 *
 */

char *readfile(char *file_name);

typedef enum { Vertex, Fragment, Compute } ShaderType;

class Shader {
public:
  unsigned int shader;
  Shader(char *filename, ShaderType type);
};

class Program {
public:
  unsigned int program;
  Program(char *computepath);
  Program(char *vertexpath, char *fragmentpath);
  Program(char *vertexpath, char *fragmentpath, char *computepath);
};

#endif
