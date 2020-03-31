#pragma once

#include <SDL.h>

#include "../core/Engine.h"

class InputHandler
{
	static InputHandler* s_instance;

	const Uint8* m_keyStates;

	void keyDown();
	void keyUp();

public:

	static InputHandler* getInstance();

	InputHandler();

	void listen();
	bool isKeyDown(SDL_Scancode key);
};
