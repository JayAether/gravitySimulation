#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>


namespace window
{
	bool init(std::string title, int width, int height);
	void cleanup();

	GLFWwindow* getContext();
}