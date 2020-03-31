#include "InputHandler.h"

InputHandler* InputHandler::s_instance = nullptr;

void InputHandler::keyDown()
{
	this->m_keyStates = SDL_GetKeyboardState(nullptr);
}

void InputHandler::keyUp()
{
	this->m_keyStates = SDL_GetKeyboardState(nullptr);
}

InputHandler* InputHandler::getInstance()
{
	if (nullptr == InputHandler::s_instance)
	{
		InputHandler::s_instance = new InputHandler();
	}
	return InputHandler::s_instance;
}

InputHandler::InputHandler()
{
	this->m_keyStates = SDL_GetKeyboardState(nullptr);
}

void InputHandler::listen()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Engine::getInstance()->quit();
			break;
		case SDL_KEYDOWN:
			this->keyDown();
			break;
		case SDL_KEYUP:
			this->keyUp();
			break;
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	// keyboardkey value 1 is pressed and 0 is released
	return this->m_keyStates[key] == 1;
}
