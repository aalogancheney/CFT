workspace "CFT"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CFT"
	location "CFT"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Engine/Source/Runtime/**.h",
		"%{prj.name}/Engine/Source/Runtime/**.cpp"
	}

	includedirs
	{

	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CFT_PLATFORM_WINDOWS",
			"CFT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CFT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CFT_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "CFT_DISTRIBUTION"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/Runtime/**.h",
		"%{prj.name}/Source/Runtime/**.cpp"
	}

	includedirs
	{
		"CFT/Engine/Source"
	}

	links
	{
		"CFT"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CFT_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "CFT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CFT_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "CFT_DISTRIBUTION"
		optimize "On"