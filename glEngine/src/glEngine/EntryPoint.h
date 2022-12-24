#pragma once

#ifdef PLATFORM_WINDOWS

// For use by glEngine Application
#include "Application.h"
#include "Log.h"

extern glEngine::Application* glEngine::CreateApplication();

int main(int argc, char* argv[])
{
	glEngine::Log::Init();
	GLENGINE_CORE_WARN("Initialized Log!");
	GLENGINE_INFO("Initialized Log!");

	auto app = glEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif