#include "pch.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int showCommand)
{
	UNREFERENCED_PARAMETER(instance);
	UNREFERENCED_PARAMETER(previousInstance);
	UNREFERENCED_PARAMETER(commandLine);
	UNREFERENCED_PARAMETER(showCommand);

	const glm::vec4 CornflowerBlue = glm::vec4(0.392f, 0.584f, 0.929f, 1.0f);

	if (!glfwInit()) //glfw
	{
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Essentials", nullptr, nullptr);
	if (window == nullptr)
	{
		return -1;
	}

	glfwMakeContextCurrent(window);  //context

	if (gl3wInit() != 0)   // loading library
	{
		return -1;
	}

	glViewport(0, 0, 800, 600);  //where to render

	while (!glfwWindowShouldClose(window))  // game loop or run loop
	{    // float, vector = array of float point value
		// 4 byte for each pixel of 800X600
		glClearBufferfv(GL_COLOR, 0, &CornflowerBlue[0]);  // clear color buffer, give it a CornflowerBlue color

		glfwSwapBuffers(window);  // double buffering : front + back buffer
		//vertical refresh/sync rate
		// handle mouse and event
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}