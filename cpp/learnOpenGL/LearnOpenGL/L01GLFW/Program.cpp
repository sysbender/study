

//include glad before glfw

#include "glad\glad.h"
#include <GLFW\glfw3.h>

#include <iostream>



/*----------callback : whenever the window size changed -----------*/
void framebuffer_size_callback(GLFWwindow * window, int width, int height) {
	// make sure the viewport matches the new window dimensions
	glViewport(0, 0, width, height);
}


// process all input
void processInput(GLFWwindow *window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

}


//settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {

	// glfw : init and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);   // uncomment this to fix compilation on OSX
#endif

	// glfw window creation
	GLFWwindow * window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Fail to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}



	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers , OS-specific  
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}
	

	// rendering loop

	while (!glfwWindowShouldClose(window)) {  // check close
		//input
		processInput(window);

		//rendering


		// set clear color , clear the screen with the color
		glClearColor(0.3f, 0.0f, 0.0f, 1.0f);   // state set function
		glClear(GL_COLOR_BUFFER_BIT);    // state using function , GL_COLOR_BUFFER_BIT/DEPTH/STENCIL

		//check and call event and swap the buffers
		glfwPollEvents();   // handle keyboard and 
		glfwSwapBuffers(window);

	}

	// release all the resource before exit
	glfwTerminate();
	
	return 0;
}

