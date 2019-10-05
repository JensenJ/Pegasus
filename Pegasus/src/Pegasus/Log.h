#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pegasus {
	class PEGASUS_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define PG_CORE_FATAL(...)	::Pegasus::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define PG_CORE_ERROR(...)	::Pegasus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PG_CORE_WARN(...)	::Pegasus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PG_CORE_INFO(...)	::Pegasus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PG_CORE_TRACE(...)	::Pegasus::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define PG_FATAL(...)		::Pegasus::Log::GetClientLogger()->critical(__VA_ARGS__)
#define PG_ERROR(...)		::Pegasus::Log::GetClientLogger()->error(__VA_ARGS__)
#define PG_WARN(...)		::Pegasus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PG_INFO(...)		::Pegasus::Log::GetClientLogger()->info(__VA_ARGS__)
#define PG_TRACE(...)		::Pegasus::Log::GetClientLogger()->trace(__VA_ARGS__)