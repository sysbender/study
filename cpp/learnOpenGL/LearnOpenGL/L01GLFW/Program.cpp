

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


// 
const char *vertexShaderSource = R"(
#version 330 core
layout (location = 0 ) in vec3 aPos;		// input vec3
void main()
	{
		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);   // predefined gl_Position, output vec4
	}
)";

const char * fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;		// output a variable FragColor type is vec4
void main(){
	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)";

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

	// --------------------build and compile the shader program--------------------------------------------

	// vertex shader
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);			// create shader , with type
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);		// specify the source
	glCompileShader(vertexShader);									// compile
	// check for error
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR : vertex shader compile :" << infoLog << std::endl;
	}

	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//check compile error
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Error: fragment shader compile :" << infoLog << std::endl;
	}

	// link shader
	int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Error: shader link :" << infoLog << std::endl;
	}

	//not needed now, delete
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//setup vertex data and buffers and configure vertex attributes
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	unsigned int vbo, vao;
	glGenBuffers(1, &vbo);   //1. create vertex buffer object
	//2. bind and set vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);		// set current GL_ARRAY_BUFFER
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);  // copy data to buffer


																				//1. bind vertex array
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//3. configure vertex attributes, get the data from current VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  // position; 3 float per vertex, type, normalize, stride in bytes, offset in buffer
	glEnableVertexAttribArray(0);




	//
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	// uncomment to draw in wireframe polygons
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// rendering loop

	while (!glfwWindowShouldClose(window)) {  // check close
		//input
		processInput(window);

		//rendering


		// set clear color , clear the screen with the color
		glClearColor(0.3f, 0.0f, 0.0f, 1.0f);   // state set function
		glClear(GL_COLOR_BUFFER_BIT);    // state using function , GL_COLOR_BUFFER_BIT/DEPTH/STENCIL

		//draw the first triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//check and call event and swap the buffers
		glfwPollEvents();   // handle keyboard and 
		glfwSwapBuffers(window);

	}

	// release all the resource before exit
	glfwTerminate();
	
	return 0;
}

