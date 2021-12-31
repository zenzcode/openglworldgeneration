#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Window.h"
#include "Helpers.h"
namespace Core {
	class Engine {
	public:
		Engine();
		~Engine();
		bool Initialize();
		void AddWindow(Core::Window* window);
		void RemoveWindow(Core::Window* window);
		void DeleteAllWindows();
	private:
		std::vector<Core::Window*> windows;
	};
}