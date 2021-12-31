#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
namespace Core{
	class Window
	{
	public:
		Window(std::string title, GLfloat width, GLfloat height, GLfloat viewportStartX, GLfloat viewportStartY);
		~Window();
		bool Initialize();
		inline GLFWwindow* GetWindow() {
			return theWindow;
		}
		inline bool ShouldWindowClose() {
			if (!theWindow) return true;
			return glfwWindowShouldClose(theWindow);
		}
	private:
		const char* title;
		GLfloat width, height;
		GLfloat viewportStartX, viewportStartY;
		GLint framebufferWidth, framebufferHeight;
		GLFWwindow* theWindow;
	};
}
