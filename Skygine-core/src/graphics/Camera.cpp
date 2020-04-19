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
	Engine::getInstance()->getWindowSize(&this->m_windowWidth, &this->m_windowHeight);

	this->m_viewport = {
		0, 0,
		this->m_windowWidth, this->m_windowHeight };

	this->m_mapTotalWidth = 0;
	this->m_mapTotalHeight = 0;
}

void Camera::updateTarget(Point* newTarget)
{
	this->m_target = newTarget;
}

void Camera::update()
{
	if (nullptr == this->m_target)
	{
		spdlog::debug("[Camera::update] The camera doesn't have any target!");
		return;
	}
	else if (this->m_mapTotalWidth == 0 || this->m_mapTotalHeight == 0)
	{
		spdlog::debug("[Camera::update] The camera doesn't have any map dimensions!");
		return;
	}

	this->m_viewport.x = this->m_target->x - (this->m_windowWidth >> 1);
	this->m_viewport.y = this->m_target->y - (this->m_windowHeight >> 1);

	MathUtils::clampInt(this->m_viewport.x, 0, this->m_mapTotalWidth - this->m_viewport.w);
	MathUtils::clampInt(this->m_viewport.y, 0, this->m_mapTotalHeight - this->m_viewport.h);

	this->m_pos = Vector2D(this->m_viewport.x, this->m_viewport.y);
}

void Camera::drawDebug()
{
	TextureManager::getInstance()->renderRect(this->m_viewport);
}

void Camera::setSceneMapDimensions(int mapTotalWidth, int mapTotalHeight)
{
	this->m_mapTotalWidth = mapTotalWidth;
	this->m_mapTotalHeight = mapTotalHeight;
}

Vector2D Camera::getPosition()
{
	return this->m_pos;
}

SDL_Rect Camera::getViewport()
{
	return this->m_viewport;
}
