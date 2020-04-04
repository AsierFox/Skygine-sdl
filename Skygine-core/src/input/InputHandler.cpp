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

bool InputHandler::isAxisKey(AxisDirection key)
{
	switch (key)
	{
	case AxisDirection::UP:
		return this->isKeyDown(SDL_SCANCODE_W) || this->isKeyDown(SDL_SCANCODE_UP);
	
	case AxisDirection::RIGHT:
		return this->isKeyDown(SDL_SCANCODE_D) || this->isKeyDown(SDL_SCANCODE_RIGHT);
	
	case AxisDirection::DOWN:
		return this->isKeyDown(SDL_SCANCODE_S) || this->isKeyDown(SDL_SCANCODE_DOWN);
	
	case AxisDirection::LEFT:
		return this->isKeyDown(SDL_SCANCODE_A) || this->isKeyDown(SDL_SCANCODE_LEFT);
	}

	return false;
}
