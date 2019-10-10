workspace "Pegasus"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Pegasus/vendor/GLFW/include"
IncludeDir["Glad"] = "Pegasus/vendor/Glad/include"
IncludeDir["ImGui"] = "Pegasus/vendor/imgui"
group "Dependencies"
	include "Pegasus/vendor/GLFW"
	include "Pegasus/vendor/Glad"
	include "Pegasus/vendor/imgui"

group ""

project "Pegasus"
	location "Pegasus"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pgpch.h"
	pchsource "Pegasus/src/pgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"PG_PLATFORM_WINDOWS",
			"PG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PG_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pegasus/vendor/spdlog/include",
		"Pegasus/src"
	}

	links
	{
		"Pegasus"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"PG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PG_DIST"
		runtime "Release"
		optimize "On"