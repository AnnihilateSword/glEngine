#pragma once
#include "Core.h"

namespace glEngine
{

	class GLENGINE_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	// TO be defined in client
	Application* CreateApplication();

}
