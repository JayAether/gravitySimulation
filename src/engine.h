#pragma once

#include <string>

namespace engine
{
	struct e_engine
	{
		double deltaTime = 0.0;
	};

	static e_engine engine;


	bool init();
	void cleanup();

	void update();
}