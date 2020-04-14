#pragma once

#include <SDL.h>

#include "../physics/Vector2D.h"
#include "AxisDirection.h"
#include "../core/Engine.h"

class InputHandler
{
	static InputHandler* s_instance;

	const Uint8* m_keyStates;

	bool m_hasMouseClicked;
	Vector2D m_mousePosition;

	InputHandler();

public:

	static InputHandler* getInstance();

	void listen();
	bool isKeyDown(SDL_Scancode key);
	bool isAxisKey(AxisDirection key);
	bool isMouseClicked();
	Vector2D getMousePosition();

private:

	void keyDown();
	void keyUp();
};
