#include "Button.h"

Button::Button(int x, int y, void (*callback)(), BaseSprite* normalStateSprite, BaseSprite* hoverStateSprite)
	: BaseUI(x, y)
{
	this->m_normalStateSprite = normalStateSprite;
	this->m_hoverStateSprite = hoverStateSprite;

	this->m_currentStateSprite = normalStateSprite;

	this->m_bounds = {
		x, y,
		static_cast<int>(this->m_currentStateSprite->getWidth()), static_cast<int>(this->m_currentStateSprite->getHeight()) };

	spdlog::debug("w {}, h {}", this->m_currentStateSprite->getWidth(), this->m_currentStateSprite->getHeight());

	this->callback = callback;
}

void Button::update()
{
	Vector2D mousePosition = InputHandler::getInstance()->getMousePosition();
	SDL_Point mousePoint = { mousePosition.x, mousePosition.y };

	if (SDL_PointInRect(&mousePoint, &this->m_bounds))
	{
		this->m_currentStateSprite = this->m_hoverStateSprite;

		if (InputHandler::getInstance()->isMouseClicked())
		{
			this->callback();
		}
	}
	else
	{
		this->m_currentStateSprite = this->m_normalStateSprite;
	}
}

void Button::draw()
{
	this->m_currentStateSprite->render(this->m_pos.x, this->m_pos.y);
}

void Button::dispose()
{
	delete this->m_currentStateSprite;

	this->m_normalStateSprite->dispose();
	delete this->m_normalStateSprite;

	this->m_hoverStateSprite->dispose();
	delete this->m_hoverStateSprite;
}
