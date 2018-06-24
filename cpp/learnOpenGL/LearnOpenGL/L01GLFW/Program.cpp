

//include glad before glfw

#include "glad\glad.h"
#include <GLFW\glfw3.h>

#include <iostream>



/*----------callback : when resizing the window-----------
void framebuffer_size_callback(GLFWwindow * window, int width, int height) {
	glViewport(0, 0, width, height);
}



*/


}

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);   // for mac


	// creat window
	GLFWwindow * window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Fail to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}



	glfwMakeContextCurrent(window);

	// OS-specific loading proc
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}
	// set the size of rendering window
	// lower left corner, width, height
	// translate -1, 1 to 0,800 and 0,600
	glViewport(0, 0, 800, 600); 


	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	

	// rendering loop

	while (!glfwWindowShouldClose(window)) {  // check close
		glfwSwapBuffers(window);
		glfwPollEvents();   // handle keyboard and 
	}

	// release all the resource before exit
	glfwTerminate();
	
	return 0;
}

