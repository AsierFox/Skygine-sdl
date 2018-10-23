#pragma once

#include <iostream>
#include <string>

#include "../src/utils/fileutils.h"

using namespace stormengine;
using namespace utils;

namespace stormengine
{
	namespace test
	{

		struct FileUtilsSpec
		{

			static void shouldReadMainFile()
			{
				std::cout << "FileUtilsSpec.shouldReadMainFile" << std::endl;


				std::string mainFile = FileUtils::read_file("src/main.cpp");

				bool assert = !mainFile.empty();

				std::cout << "Should read main file: " << assert << std::endl;
			}
		};

	}
}
