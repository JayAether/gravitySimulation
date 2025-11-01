#include "window.h"



#include <iostream>

namespace window
{
	struct i_window
	{
		std::string name;
		int scrWidth, scrHeight;
		GLFWwindow* context;
	};

	static i_window _window;

	bool init(std::string title, int width, int height)
	{
		_window.name = title;
		_window.scrWidth = width;
		_window.scrHeight = height;

		if (!glfwInit())
		{
			std::cout << "couldnt init glfw\n";
			return false;
		}

		glfwInitHint(GLFW_VERSION_MAJOR, 3);
		glfwInitHint(GLFW_VERSION_MINOR, 4);
		glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		_window.context = glfwCreateWindow(_window.scrWidth, _window.scrHeight, _window.name.c_str(), nullptr, nullptr);
		if (!_window.context)
		{
			std::cout << "failed to create window\n";
			return false;
		}

		glfwMakeContextCurrent(_window.context);


		return true;
	}

	void cleanup()
	{
		glfwTerminate();
	}

	GLFWwindow* getContext()
	{
		return _window.context;
	}

}

