workspace "Tangram"
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
IncludeDir["GLFW"] = "Tangram/vendor/GLFW/include"
IncludeDir["Glad"] = "Tangram/vendor/Glad/include"
IncludeDir["glm"] = "Tangram/vendor/glm"
IncludeDir["ImGui"] = "Tangram/vendor/imgui"

group "Dependencies"
	include "Tangram/vendor/GLFW"
	include "Tangram/vendor/Glad"
	include "Tangram/vendor/imgui"


group ""
project "Tangram"
	location "Tangram"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tgpch.h"
	pchsource "Tangram/src/tgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	includedirs{
		 "%{prj.name}/src",
		 "%{prj.name}/vendor/spdlog/include",
		 "%{IncludeDir.GLFW}",
		 "%{IncludeDir.Glad}",
		 "%{IncludeDir.glm}",
		 "%{IncludeDir.ImGui}"
	}
	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	} 
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"TG_PLATFORM_WINDOWS",
			"TG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "TG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TG_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Tangram/vendor/spdlog/include",
		"Tangram/src",
		"Tangram/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Tangram"
	}
	filter "system:windows"
		systemversion "latest"
		defines
		{
			"TG_PLATFORM_WINDOWS"

		}
	filter "configurations:Debug"
		defines "TG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TG_DIST"
		runtime "Release"
		optimize "on"