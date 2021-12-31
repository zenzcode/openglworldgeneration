#include <iostream>
#include "Engine.h"
#include "Window.h"

void CollectAndPrintErrors() {
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		std::cerr << "Error Code: " << std::hex << error << std::endl;
	}
}

int main()
{
	Core::Engine* voxelEngine = new Core::Engine();
	voxelEngine->Initialize();
	Core::Window* mainWindow = new Core::Window("Voxel Engine", 1920, 1080, 0, 0);
	mainWindow->Initialize();
	voxelEngine->AddWindow(mainWindow);

	GLFWwindow* glWindow = mainWindow->GetWindow();
	if (!glWindow) return -1;

	while (!mainWindow->ShouldWindowClose()) {
		glfwPollEvents();
		glClearColor(0.175f, 0.175f, 0.175f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		CollectAndPrintErrors();

		glfwSwapBuffers(glWindow);
	}
	return 0;
}