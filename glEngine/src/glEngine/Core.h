#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define GLENGINE_API __declspec(dllexport)
	#else
		#define GLENGINE_API __declspec(dllimport)
	#endif
#else
	#error glEngine only support Windows!
#endif