#include <logger.h>
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

Logger::Logger() {
}

Logger* Logger::get_instance() {
	static Logger* instance = nullptr;
	
	if(instance == nullptr) {
		instance = new Logger();

		// GLOBAL CHANGE LOG PATTERN
    	spdlog::set_pattern("%m-%d-%Y %H:%M:%S %z %^--%L--%$ %v");
	
		// CREATE LOGS
		instance->init_file_logger("file_logger", "/home/scott/file_logger.txt", 1024 * 1024 * 5, 3);
		instance->init_console_logger("console_logger");
	}

	return instance;
}

void Logger::init_file_logger(std::string name, spdlog::filename_t filepath, std::size_t max_file_size, std::size_t max_files) {
	this->m_file_logger = spdlog::rotating_logger_mt(name, filepath, max_file_size, max_files);
}

void Logger::init_console_logger(std::string name) {
   this->m_console_logger = spdlog::stdout_color_mt(name);
}

void Logger::log_to_file(spdlog::level::level_enum level, std::string msg) {
	Logger::get_instance()->m_file_logger->log(level, msg);
}

void Logger::log_to_console(spdlog::level::level_enum level, std::string msg) {
	Logger::get_instance()->m_console_logger->log(level, msg);
}