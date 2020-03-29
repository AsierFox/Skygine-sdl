#pragma once

#include <string>

struct FileUtils
{
	/**
	 * Read file using standard C style, it is much faster than C++ way.
	 */
	static std::string read_file(const char* path);
};
