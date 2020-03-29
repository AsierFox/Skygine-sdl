#include "FileUtils.h"

std::string FileUtils::read_file(const char* path)
{
	FILE* file = nullptr;

	// r to read & t to interpret as a text file, to read also line endings.
	fopen_s(&file, path, "rt");

	// Getting size of the file
	// Ubicate at the end of the file
	fseek(file, 0, SEEK_END);

	// Get seek position length to know the size of the file
	unsigned long fileSize = ftell(file);
	// Add +1 to add termination string in C++
	char* data = new char[fileSize + 1];
	// Fill array with 0 value
	memset(data, 0, fileSize + 1);

	// Reset seek position
	fseek(file, 0, SEEK_SET);
	// Get file to data
	fread(data, 1, fileSize, file);
	fclose(file);

	std::string result(data);

	delete[] data;

	return result;
}
