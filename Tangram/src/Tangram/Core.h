#pragma once

#ifdef TG_PLATFORM_WINDOWS
	#ifdef TG_BUILD_DLL
		#define TANGRAM_API __declspec(dllexport)
	#else
		#define TANGRAM_API __declspec(dllimport)
	#endif
#else
	#error Hazel only support windows!
#endif // DEBUG

#define BIT(x) (1 << x)