#include "Logger.h"

#pragma region public_methods

Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::log(std::string msg) {
	std::cout << msg << std::endl;
}

void Logger::error(std::string msg) {
	std::cout << msg << std::endl;
}

#pragma endregion
