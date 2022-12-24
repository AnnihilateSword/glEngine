#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace glEngine
{

	class GLENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define GLENGINE_CORE_TRACE(...)	::glEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GLENGINE_CORE_INFO(...)		::glEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GLENGINE_CORE_WARN(...)		::glEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GLENGINE_CORE_ERROR(...)	::glEngine::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client log macros
#define GLENGINE_TRACE(...)			::glEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GLENGINE_INFO(...)			::glEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GLENGINE_WARN(...)			::glEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GLENGINE_ERROR(...)			::glEngine::Log::GetClientLogger()->error(__VA_ARGS__)