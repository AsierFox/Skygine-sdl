#include <spdlog/spdlog.h>

#include "src/core/Engine.h"

int main(int argc, char* argv[])
{
	spdlog::set_level(spdlog::level::debug);

	Engine::getInstance()->init();

	while (Engine::getInstance()->isRunning())
	{
		Engine::getInstance()->events();
		Engine::getInstance()->update(0);
		Engine::getInstance()->draw();
	}

	Engine::getInstance()->dispose();

	return EXIT_SUCCESS;
}
