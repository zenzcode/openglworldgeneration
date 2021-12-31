#include "Window.h"

Core::Window::Window(std::string title, GLfloat width, GLfloat height, GLfloat viewportStartX, GLfloat viewportStartY): title(title.c_str()), width(width), height(height),
	viewportStartX(viewportStartX), viewportStartY(viewportStartY){
}

bool Core::Window::Initialize() {
	if (theWindow != nullptr) {
		std::cerr << "Window already exists for this class." << std::endl;
		return false;
	}

	theWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!theWindow) {
		std::cerr << "Window could not be created." << std::endl;
		glfwDestroyWindow(theWindow);
		return false;
	}

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwGetFramebufferSize(theWindow, &framebufferWidth, &framebufferHeight);
	glViewport(viewportStartX, viewportStartY, framebufferWidth, framebufferHeight);
	glfwMakeContextCurrent(theWindow);
	return true;
}
Core::Window::~Window() {
	if (!theWindow) return;
	glfwDestroyWindow(theWindow);
}