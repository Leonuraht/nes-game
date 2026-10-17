#include "misc/cgltf.h"
#include "misc/initgl.hpp"
#include "misc/shaders.hpp"

float vertices[] = {
    -0.5f, 0.5f,  0.0f, // Top-left
    0.5f,  0.5f,  0.0f, // Top-right
    0.5f,  -0.5f, 0.0f, // Bottom  right
    -0.5f, 0.5f,  0.0f, // Top-left
    0.5f,  -0.5f, 0.0f, // Bottom-right
    -0.5f, -0.5f, 0.0f  // Bottom left
};

int main() {

  GLFWwindow *window;
  if ((window = initialize()) == NULL) {
    return -1;
  }

  // Object
  unsigned int VAO, VBO;
  glCreateVertexArrays(1, &VAO);
  glCreateBuffers(1, &VBO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
  glEnableVertexAttribArray(0);


  // Shader
  Program program_basic("./src/shaders/vertex_basic.glsl",
                        "./src/shaders/fragment_basic.glsl");

  while (!glfwWindowShouldClose(window)) {
    process_input(window);

  glClearColor(0.2f, 0.3f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program_basic.program);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
