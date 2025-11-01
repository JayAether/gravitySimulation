#include "engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace engine
{
	void calculateDeltaTime();

	struct i_engine
	{
		double currentFrameTime = 0.0;
		double lastFrameTime = 0.0;
	};

	static i_engine _engine;

	bool init()
	{
		if (!gladLoadGL())
		{
			std::cout << "failed to init glad\n";
			return  false;
		}

		return true;
	}

	void cleanup()
	{
		
	}

	void update()
	{
		calculateDeltaTime();
	}

	void calculateDeltaTime()
	{
		_engine.currentFrameTime	= glfwGetTime();
		engine.deltaTime			= _engine.currentFrameTime - _engine.lastFrameTime;
		_engine.lastFrameTime		= _engine.currentFrameTime;
	}
}