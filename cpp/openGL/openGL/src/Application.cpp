
#include <GL/glew.h>   

#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

#define ASSERT(x) if(!(x)) __debugbreak();

#define GLCall(x) GLClearError(); \
	x; \
	ASSERT(GLLogCall(#x, __FILE__, __LINE__));   // # change x to a string

static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char * function , const char * file, int line)
{
	while( GLenum error = glGetError())
	{
		std::cout << " openGL Error :" << error 
		<<":" << function
		<< ":" << file
		<< ":" << line
		<< std::endl;
		return false;
	}
	return true;
}
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string & filepath)
{
	std::ifstream stream(filepath);


	enum class ShaderType
	{
		None = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	ShaderType type = ShaderType::None;

	std::string line;
	std::stringstream ss[2]; // vertex and fragment
	while(getline(stream, line))
	{
		if((line.find("#shader")) != std::string::npos)
		{
			if(line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}else if(line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}else
		{
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}


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

	float positions[] = {
		-0.5f, -0.5f, //0
		0.5f, -0.5f,   //1
		0.5f, 0.5f ,  //2
  		-0.5f, 0.5f,  //3 
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);  // anything generated in GPU get a id, vertex buffer/texture/shader
	glBindBuffer(GL_ARRAY_BUFFER, buffer); // select 
	// put data into buffer
	glBufferData(GL_ARRAY_BUFFER, 6 * 2* sizeof(float), positions, GL_STATIC_DRAW);

	// attribute - buffer layout
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);  // pointer = offset
	glEnableVertexAttribArray(0);




	//
	unsigned int ibo;   // index buffer object
	glGenBuffers(1, &ibo);  // anything generated in GPU get a id, vertex buffer/texture/shader
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , ibo); // select 
										   // put data into buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 *  sizeof(unsigned int), indices, GL_STATIC_DRAW);



	//-----------------------------get shader source
	ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");  // vs debug set work dir = $(projectDir)

	const std::string vertexShader = source.VertexSource;

	const std::string fragmentShader = source.FragmentSource;

	std::cout <<"---------vertex shader---------\n"<< vertexShader.c_str();
	std::cout << "---------fragement shader---------\n" << fragmentShader.c_str();


	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		GLClearError();
		// 
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr));
		//ASSERT(GLLogCall());

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
