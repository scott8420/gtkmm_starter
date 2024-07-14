#ifndef __LOGGER__
#define __LOGGER__

#include <spdlog/spdlog.h>
#include <format>

class Logger {
private:
    Logger(); 

public:
	Logger(const Logger&) = delete;

    static Logger* get_instance();
	void init_file_logger(std::string, spdlog::filename_t, std::size_t, std::size_t);
	void init_console_logger(std::string);

	void log_to_file(spdlog::level::level_enum, std::string);
	void log_to_console(spdlog::level::level_enum, std::string);

private:
	std::shared_ptr<spdlog::logger> m_file_logger = nullptr;
	std::shared_ptr<spdlog::logger> m_console_logger = nullptr;
};

// CONVENIENCE MACROS
#define FORMAT(message) std::format("{}:{} | {}: {}", __FILE__, __LINE__, __FUNCTION__, message)

#define LOG_TO_FILE(level, message) Logger::get_instance()->log_to_file(level, message)
#define LOG_TRACE_TO_FILE(message)    LOG_TO_FILE(spdlog::level::trace, FORMAT(message))
#define LOG_DEBUG_TO_FILE(message)    LOG_TO_FILE(spdlog::level::debug, FORMAT(message))
#define LOG_INFO_TO_FILE(message)     LOG_TO_FILE(spdlog::level::info, FORMAT(message))
#define LOG_WARN_TO_FILE(message)     LOG_TO_FILE(spdlog::level::warn, FORMAT(message))
#define LOG_ERR_TO_FILE(message)      LOG_TO_FILE(spdlog::level::err, FORMAT(message))
#define LOG_CRITICAL_TO_FILE(message) LOG_TO_FILE(spdlog::level::critical, FORMAT(message))

#define LOG_TO_CONSOLE(level, message) Logger::get_instance()->log_to_console(level, message)
#define LOG_TRACE_TO_CONSOLE(message)    LOG_TO_CONSOLE(spdlog::level::trace, FORMAT(message))
#define LOG_DEBUG_TO_CONSOLE(message)    LOG_TO_CONSOLE(spdlog::level::debug, FORMAT(message))
#define LOG_INFO_TO_CONSOLE(message)     LOG_TO_CONSOLE(spdlog::level::info, FORMAT(message))
#define LOG_WARN_TO_CONSOLE(message)     LOG_TO_CONSOLE(spdlog::level::warn, FORMAT(message))
#define LOG_ERR_TO_CONSOLE(message)      LOG_TO_CONSOLE(spdlog::level::err, FORMAT(message))
#define LOG_CRITICAL_TO_CONSOLE(message) LOG_TO_CONSOLE(spdlog::level::critical, FORMAT(message))

#endif
