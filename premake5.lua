workspace "glEngine"
	architecture "x64"

	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "glEngine"
	location "glEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
			"BUILD_DLL",
		}

		postbuildcommands 
		{ 
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
		}

	filter "configurations:Debug"
		defines "GLENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GLENGINE_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "GLENGINE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"glEngine/src",
		"glEngine/vendor/spdlog/include",
	}

	links
	{
		"glEngine",
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "GLENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GLENGINE_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "GLENGINE_DIST"
		optimize "On"