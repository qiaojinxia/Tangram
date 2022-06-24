#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Tangram {
	class TANGRAM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//CORE LOG MACROS
#define TG_CORE_ERROR(...)	::Tangram::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TG_CORE_WARN(...)	::Tangram::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TG_CORE_INFO(...)	::Tangram::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TG_CORE_TRACE(...)	::Tangram::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TG_CORE_FATAL(...)	::Tangram::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//CLIENT LOG MACROS
#define TG_CLIENT_ERROR(...)	::Tangram::Log::GetClientLogger()->error(__VA_ARGS__)
#define TG_CLIENT_WARN(...)		::Tangram::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TG_CLIENT_INFO(...)		::Tangram::Log::GetClientLogger()->info(__VA_ARGS__)
#define TG_CLIENT_TRACE(...)	::Tangram::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TG_CLIENT_FATAL(...)	::Tangram::Log::GetClientLogger()->fatal(__VA_ARGS__)