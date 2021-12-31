#include "Engine.h"
Core::Engine::Engine() {

}

bool Core::Engine::Initialize() {
	if (!glfwInit()) {
		std::cerr << "GLFW could not be Initialized." << std::endl;
		DeleteAllWindows();
		glfwTerminate();
		return false;
	}

	glewExperimental = GL_TRUE;
	if (!glewInit()) {
		std::cerr << "GLEW could not be Initialized." << std::endl;
		DeleteAllWindows();
		glfwTerminate();
		return false;
	}
	return true;
}



void Core::Engine::AddWindow(Core::Window* window) {
	windows.push_back(window);
}

void Core::Engine::RemoveWindow(Core::Window* window) {
	std::vector<Core::Window*>::iterator position = std::find(windows.begin(), windows.end(), window);
	if (position == windows.end()) return;
	windows.erase(position);
}

void Core::Engine::DeleteAllWindows() {
	for (auto& window : windows) {
		SafeDelete(window);
	}
}