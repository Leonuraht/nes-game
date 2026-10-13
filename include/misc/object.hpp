#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "glad/glad.h"
#include <array>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

/*
 *
 *        Provides Functions Used to initalise and use Objects
 *
 *
 */

class VBO {
public:
  void *data;
  size_t size;
};

template <size_t N> class VAO : public VBO {
public:
  std::array<unsigned int, N> vao;
};

#endif
