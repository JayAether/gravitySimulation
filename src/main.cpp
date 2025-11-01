#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "engine.h"

#include <iostream>

int main()
{
	window::init("gravity sim", 800, 600);
	engine::init();


	std::cout << "hello gravity\n";


	while (!glfwWindowShouldClose(window::getContext()))
	{
		glfwPollEvents();
	}


	engine::cleanup();
	window::cleanup();
}