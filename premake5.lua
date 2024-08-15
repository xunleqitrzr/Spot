workspace "Spot"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Spot"
	location "Spot"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SP_PLATFORM_WINDOWS",
			"SP_BUILD_DLL",
			"_WINDLL",
			"_UNICODE",
			"UNICODE"
		}

		postbuildcommands
		{
			("{COPY} %(cfg.buildtarget.relpath) ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include",
		"Spot/src"
	}

	links
	{
		"Spot"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SP_PLATFORM_WINDOWS",
			"_UNICODE",
			"UNICODE"
		}

	filter "configurations:Debug"
		defines "SP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SP_DIST"
		optimize "On"