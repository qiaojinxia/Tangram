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

#ifdef  TG_ENABLE_ASSERTS
	#define TG_ASSERT(x,...) { if(!(x)) {TG_ERROR("Assertion Failed:{0}",__VA__ARGS__);__debugbreak();}}
	#define TG_CORE_ASSERT(x,...) { if(!(x)) {TG_CORE_ERROR("Assertion Failed:{0}",__VA__ARGS__);__debugbreak();}}
#else
	#define TG_ASSERT(x,...)
	#define TG_CORE_ASSERT(x,...)
#endif //  TG_ENABLEF_ASSERTS

#define BIT(x) (1 << x)