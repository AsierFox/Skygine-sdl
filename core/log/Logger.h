#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <string>

/**
 * Logger class for debugging.
 */
class Logger {
public:
	Logger();
	~Logger();

	/**
	* Shows a log message.
	*/
	static void log(std::string msg);

	/**
	 * Shows an error message.
	 */
	static void error(std::string msg);
};

#endif // !_LOGGER_H_
