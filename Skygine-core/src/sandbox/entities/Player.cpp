#include "Player.h"

Player::Player(std::string id, std::string name, int x, int y)
	: GameObject(id, name, x, y)
{
	this->m_idleAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 1, 2, 4, 3, 3);
	this->m_walkAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 3, 4, 4, 3, 3);
	this->m_currentAnimation = this->m_idleAnimation;

	this->m_origin = new Point(x + (this->m_currentAnimation->getWidth() / 2), y + (this->m_currentAnimation->getHeight() / 2));

	this->m_rigitBody = new RigitBody();
}

void Player::update(float delta)
{
	this->m_rigitBody->removeForce();
	
	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_D))
	{
		this->m_rigitBody->setForceX(3.0f);
	}

	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_A))
	{
		this->m_rigitBody->setForceX(-3.0f);
	}

	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_W))
	{
		this->m_rigitBody->setForceY(-3.0f);
	}

	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_S))
	{
		this->m_rigitBody->setForceY(3.0f);
	}

	this->m_rigitBody->update(delta);
	this->m_transform->translateX(this->m_rigitBody->getPosition().x);
	this->m_transform->translateY(this->m_rigitBody->getPosition().y);

	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getHeight() / 2);

	if (this->m_rigitBody->getForce().x != 0 || this->m_rigitBody->getForce().y != 0)
	{
		this->m_currentAnimation = m_walkAnimation;
	}
	else
	{
		this->m_currentAnimation = this->m_idleAnimation;
	}
	this->m_currentAnimation->update();
}

void Player::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);

	TextureManager::getInstance()->renderPoint(this->m_origin->x, this->m_origin->y);
}

void Player::dispose()
{
	// TODO Dispose Sprites
}
