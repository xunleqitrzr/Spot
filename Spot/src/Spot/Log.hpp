#pragma once

#include <memory>

#include "Core.hpp"
#include "spdlog/spdlog.h"

namespace Spot {
	
	class SPOT_API Log
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
#define SP_CORE_TRACE(...)       ::Spot::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)        ::Spot::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...)        ::Spot::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...)       ::Spot::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_FATAL(...)       ::Spot::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SP_TRACE(...)            ::Spot::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)             ::Spot::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_WARN(...)             ::Spot::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...)            ::Spot::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_FATAL(...)            ::Spot::Log::GetClientLogger()->fatal(__VA_ARGS__)