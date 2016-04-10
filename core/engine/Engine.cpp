#include "Engine.h"

Engine::State Engine::state = INVALID;

#pragma region public_methods

Engine::Engine() {
	state = LOADING;
}

Engine::~Engine() {
	state = SHUTDOWN;
}

int Engine::loop() {

	Context context;

	if (!init()) {
		Logger::error("Engine.cpp[Engine::loop()] Error initializing the engine");
		return 0;
	}

	MSG msg = {};

	state = RUNNING;
	
	/* Initialize the randomization */
	srand(GetTickCount());

	while (state == RUNNING && msg.message != WM_QUIT) {
		//resize()

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		update(context);
		render(context);
	}

	Logger::log("Destroying the program");
	if (!destroy()) {
		Logger::error("Engine.cpp[Engine::loop()] Error destroying the engine");
		return 0;
	}

	return msg.wParam;
}

#pragma endregion

#pragma region private_methods

int Engine::init() {
	state = INIT;

	Game* game = createGame();
	if (!game) {
		Logger::error("Engine.cpp[Engine::init()] game is null.");
		return false;
	}

	/* Add systems */


	return true;
}

int Engine::render(const Context& context) {

	return true;
}

int Engine::update(const Context& context) {

	return true;
}

int Engine::destroy() {
	state = DESTROY;

	/* Remove systems */
	/*
	for (std::pair<System::Type, System*> pSystem : systems) {
		if (!pSystem.second->destroy()) {
			Logger::error("Engine.cpp[Engine::destroy()] pSystem was null.");
			continue;
		}
		SAFE_DELETE(pSystem.second);
	}
	*/

	return true;
}

Game* Engine::createGame() {
	GameData data;
	if (!addSystem(new Game(data))) {
		Logger::error("Engine.cpp[Engine::createGame()] error creating Game.");
		return nullptr;
	}

	Game* game = getSystem<Game>(System::GAME);
	if (!game) {
		Logger::error("Engine.cpp[Engine::createGame()] error getting Game system.");
		return nullptr;
	}
	/*
	if (!game->init()) {
		Logger::error("Engine.cpp[Engine::createGame()] error getting Game system.");
		return nullptr;
	}
	*/
	return game;
}

int Engine::addSystem(System* pSystem) {
	auto addedSystem = systems.insert(std::pair<System::Type, System*> (pSystem->getType(), pSystem));
	if (!addedSystem.second) {
		return false;
	}
	return true;
}

template<typename T>
T* Engine::getSystem(System::Type systemType) {
	T* pSystem = static_cast<T*>(systems[systemType]);
	if (!pSystem) {
		Logger::error("Engine.cpp[Engine::getSystem()] pSystem is null.");
		return nullptr;
	}
	return pSystem;
}

#pragma endregion
