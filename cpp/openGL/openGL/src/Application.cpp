
#include <GL/glew.h>   

#include <GLFW/glfw3.h>

#include <iostream>


static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char * src = source.c_str();
	//const char * src = &source[0];
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	// TODO: error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		std::cout << "error_message_length = " << length << std::endl;
		char *message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		std::cout << "Failed to compile shader!"
			<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
			<< std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

static unsigned int CreateShader(const std::string & vertexShader, const std::string & fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;



	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}




	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	// after get context , we can run grewInit
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error: in glewinit" << std::endl;
	}

	std::cout << "opengl version = " << glGetString(GL_VERSION) << std::endl;

	// modern opengl , draw a rectangle
	// 1. vertex buffer  - in GPU ram
	// 2. shader - code run on GPU, specify how the data will be drawn

	float positions[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f };

	unsigned int buffer;
	glGenBuffers(1, &buffer);  // anything generated in GPU get a id, vertex buffer/texture/shader
	glBindBuffer(GL_ARRAY_BUFFER, buffer); // select 
	// put data into buffer
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	// attribute - buffer layout
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);  // pointer = offset
	glEnableVertexAttribArray(0);

	//-----------------------------

	const std::string vertexShader = R"(
	#version 330 core

	layout(location = 0) in vec4 position;
		
	void main()
		{
			gl_Position = position;

		}
	)";

	const std::string fragmentShader = R"(
	#version 330 core

	layout(location = 0) out vec4 color;
		
	void main()
		{
			color = vec4(1.0, 0.0, 0.0, 1.0);
		}
	)";

	std::cout << vertexShader.c_str();
	std::cout << fragmentShader.c_str();


	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		// 
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//--------------my test code legacy
		//glBegin(GL_TRIANGLES);
		//glVertex2d(-0.5f, -0.5f);
		//glVertex2d(0.0f, 0.5f);
		//glVertex2d(0.5f, -0.5f);
		//glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	// delete shader
	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}
