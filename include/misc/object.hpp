#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "glad/glad.h"
#define GLAD_INCLUDE_NONE
#include "GLFW/glfw3.h"

/*
 *
 *        Provides Functions Used to create and GL Objects and buffers.
 *
 *
 */

class Object {
private:
  unsigned int VAO, VBO, EBO;

public:
  Object() {}
};

#endif
