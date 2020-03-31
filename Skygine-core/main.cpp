#include <spdlog/spdlog.h>
#include <SDL.h>

#include "src/sandbox/ExSideGame.h"

int main(int argc, char* argv[])
{
	spdlog::set_level(spdlog::level::debug);

	ExSideGame* game = new ExSideGame();

	bool isGameInit = game->init();

	if (!isGameInit)
	{
		spdlog::critical("Game engine could not been initialize!");
		return EXIT_FAILURE;
	}

	while (game->isRunning())
	{
		game->events();
		game->update(.2f);
		game->draw();
	}

	game->dispose();

	return EXIT_SUCCESS;
}
