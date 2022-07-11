workspace "Tangram"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}	
IncludeDir["GLFW"] = "Tangram/vendor/GLFW/include"

include "Tangram/vendor/GLFW"

project "Tangram"
	location "Tangram"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tgpch.h"
	pchsource "Tangram/src/tgpch.cpp"
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	includedirs{
		 "%{prj.name}/src",
		 "%{prj.name}/vendor/spdlog/include",
		 "%{IncludeDir.GLFW}"
	}
	links{
		"GLFW",
		"opengl32.lib"
	} 
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"   
		systemversion "latest"
	defines
	{
		"TG_PLATFORM_WINDOWS",
		"TG_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}
	filter "configurations:Debug"
		defines "TG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TG_DIST"
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
	includedirs{
		 "Tangram/vendor/spdlog/include",
		 "Tangram/src"

	}
	links
	{
		"Tangram"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"   
		systemversion "latest"
	defines
	{
		"TG_PLATFORM_WINDOWS"
	}
	filter "configurations:Debug"
		defines "TG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "TG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TG_DIST"
		buildoptions "/MD"
		optimize "On"