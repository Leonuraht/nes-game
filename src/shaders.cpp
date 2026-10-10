#include "misc/shaders.hpp"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>

static long sizeoffile(FILE *file) {
  fseek(file, 0, SEEK_END);
  long val = ftell(file);
  fseek(file, 0, SEEK_SET);
  return val;
}

char *readfile(char *file_name) {
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    std::cerr << "ERROR : FILE READING FAILED.\n" << std::endl;
    return NULL;
  }
  size_t filesize = (size_t)sizeoffile(file);
  char *buffer = (char *)malloc(filesize + 1);
  if (buffer == NULL) {
    std::cerr << "ERROR : FILE BUFFER ALLOCATION FAILED.\n" << std::endl;
    fclose(file);
    return NULL;
  }
  if (fread(buffer, 1, filesize, file) != filesize) {
    free(buffer);
    fclose(file);
    return NULL;
  }
  buffer[filesize] = '\0';
  fclose(file);
  return buffer;
}

Shader::Shader(char *filename, ShaderType type) {
  const char *filedata = (const char *)readfile(filename);
  switch (type) {
  case Vertex:
    shader = glCreateShader(GL_VERTEX_SHADER);
    break;
  case Fragment:
    shader = glCreateShader(GL_FRAGMENT_SHADER);
    break;
  case Compute:
    shader = glCreateShader(GL_COMPUTE_SHADER);
    break;
  }
  glShaderSource(shader, 1, &filedata, NULL);
  glCompileShader(shader);

  int success;
  char infoLog[512];

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cout << "ERROR : SHADER COMPILATION_FAILED" << type << " " << infoLog
              << std::endl;
  }
}

Program::Program(char *vertexpath, char *fragmentpath) {
  Shader vertexshader(vertexpath, Vertex);
  Shader fragmentshader(fragmentpath, Fragment);
  program = glCreateProgram();
  glAttachShader(program, vertexshader.shader);
  glAttachShader(program, fragmentshader.shader);
  glLinkProgram(program);

  int success;
  char infoLog[512];

  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(program, 512, NULL, infoLog);
    std::cout << "ERROR : PROGRAM COMPILATION_FAILED" << infoLog << std::endl;
  }
}

Program::finished() {
  glDeleteShader(vertexshader.shader);
  glDeleteShader(fragmentshader.shader);
}
