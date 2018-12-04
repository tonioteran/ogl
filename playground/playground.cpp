/**
 * @file playground.cpp
 * @brief quick tests for openGL
 * @author Antonio Teran, teran@mit.edu
 * @date December 04, 2018
 */

#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h> // for handling window and keyboard
#include <glm/glm.hpp>

int main() {

  // initialize GLFW
  glewExperimental = true;
  if ( !glfwInit() ) {
    fprintf( stderr, "Failed to initialize GLFW\n" );
    return (-1);
  }

  // Create OpenGL windows:
  glfwWindowHint(GLFW_SAMPLES, 4);               /* 4x antialiasing */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); /* want OpenGL 3.3 */
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window;
  window = glfwCreateWindow( 1024, 768, "Custom Playground", NULL, NULL );
  if ( window == NULL ) {
    fprintf( stderr, "Failed to open GLFW window." );
    glfwTerminate();
    return (-1);
  }

  glfwMakeContextCurrent( window ); /* initialize GLEW */
  if ( glewInit() != GLEW_OK ) {
    fprintf( stderr, "Failed to initialize GLEW\n" );
    return (-1);
  }

  // Ensure we can capture the escape key
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  do {
    glClear( GL_COLOR_BUFFER_BIT ); // clear the screen
    // draw nothing...
    glfwSwapBuffers(window);
    glfwPollEvents();
  } while ( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && 
      glfwWindowShouldClose(window) == 0 );

  return (0);
}
