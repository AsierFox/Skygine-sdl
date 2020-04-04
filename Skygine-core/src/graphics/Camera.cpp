#include "Camera.h"

Camera* Camera::s_instance = nullptr;

Camera* Camera::getInstance()
{
	if (nullptr == Camera::s_instance)
	{
		Camera::s_instance = new Camera;
	}

	return Camera::s_instance;
}

Camera::Camera()
{
	// TODO Check if Full Screen -> FullScreen (SDL_GetRendererOutputSize), NO FullScreen (SDL_GetDesktopDisplayMode)
	if (SDL_GetDesktopDisplayMode(0, &this->m_displayMode) != 0)
	{
		spdlog::critical("[Camera::Camera()] SDL_GetDesktopDisplayMode error: {0}", SDL_GetError());
	}

	this->m_viewport = {
		0, 0,
		this->m_displayMode.w, this->m_displayMode.h };
}

void Camera::update(float delta)
{
	if (nullptr == this->m_target)
	{
		spdlog::critical("[Camera::update] The camera doesn't have any target!");
		return;
	}

	this->m_viewport.x = this->m_target->x - (this->m_displayMode.w / 2);
	this->m_viewport.y = this->m_target->y - (this->m_displayMode.h / 2);
	// TODO Add dynamic width to camera (getting the width of the map i.e.),
	// Add to the update target, the width o the worldmap
	MathUtils::clampInt(this->m_viewport.x, 0, (this->m_displayMode.w + 250) - this->m_viewport.w);
	MathUtils::clampInt(this->m_viewport.y, 0, (this->m_displayMode.h + 300) - this->m_viewport.h);

	this->m_pos = Vector2D(this->m_viewport.x, this->m_viewport.y);
}

void Camera::updateTarget(Point* newTarget)
{
	this->m_target = newTarget;
}

Vector2D Camera::getPosition()
{
	return this->m_pos;
}

SDL_Rect Camera::getViewport()
{
	return this->m_viewport;
}
