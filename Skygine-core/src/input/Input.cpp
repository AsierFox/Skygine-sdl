#include "Input.h"

Input* Input::s_instance = nullptr;

Input* Input::getInstance()
{
	if (nullptr == Input::s_instance)
	{
		Input::s_instance = new Input();
	}
	return Input::s_instance;
}
