#ifndef _ENGINE_H_
#define _ENGINE_H_

#ifndef _WINDOW_
	#include <Windows.h>
#endif // _WINDOW_

#include <string>
#include <map>

#include "../../defines/deletemacros.h"
#include "../log/Logger.h"
#include "../../defines/context.h"

#include "../system/System.h"
#include "../system/Game.h"

/*
 * Engine class to manage the states and the Game creation.
 */
class Engine {

	std::map<System::Type, System*> systems;

	/**
	 * Initialize the engine.
	 * Returns 0 if all was fine
	 */
	int init();

	/**
	* Renders the engine graphics.
	* Returns 0 if all was fine
	*/
	int render(const Context& context);

	/**
	* Updates the engine objets logic.
	* Returns 0 if all was fine
	*/
	int update(const Context& context);

	/**
	* Destroys the engine.
	* Returns 0 if all was fine
	*/
	int destroy();

	/**
	* Creates the Game.
	* Returns the Game instance
	*/
	Game* createGame();

	/**
	* Adds a core system to the engine.
	* Returns 0 if all was fine
	*/
	int addSystem(System* pSystem);

	/**
	* Gets a current core system from the engine.
	* Returns an specific core system
	*/
	template<typename T>
	T* getSystem(System::Type systemType);

public:
	enum State {
		INVALID,
		LOADING,
		INIT,
		RUNNING,
		SHUTDOWN,
		DESTROY
	};
	static State state;

	Engine();
	~Engine();

	/**
	* Runs the loop of the engine.
	* Returns an specific core system
	*/
	int loop();

	//void* operator new(size_t size);
	//void operator delete(void* pDelete);
};

#endif // !_ENGINE_H_
