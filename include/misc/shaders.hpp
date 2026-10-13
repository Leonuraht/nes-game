#ifndef SHADER_HPP
#define SHADER_HPP
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <iostream>

/*
 *
 *        Provides Functions Used to create and read shaders.
 *
 *
 */

char *readfile(const char *file_name);

typedef enum { Vertex, Fragment, Compute } ShaderType;

class Shader {
public:
  unsigned int shader;

  Shader(const char *filename, ShaderType type);
  void deletes();
};

class Program {
public:
  unsigned int program;

  Program(const char *computepath);
  Program(const char *vertexpath, const char *fragmentpath);
  Program(const char *vertexpath, const char *fragmentpath,
          const char *computepath);
};

#endif
