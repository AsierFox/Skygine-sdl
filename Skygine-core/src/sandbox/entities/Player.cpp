#include "Player.h"

Player::Player(std::string id, std::string name, int x, int y)
	: GameObject(id, name, x, y)
{
	this->spriteAnimation = new SpriteAnimation(id, "assets/nyson-sheet.png", 1, 2, 2, 5);
	this->rigitBody = new RigitBody();
}

void Player::update(float delta)
{
	this->spriteAnimation->update();
	
	this->rigitBody->setForceX(3.0f);

	this->rigitBody->update(delta);
	this->m_transform->translateX(this->rigitBody->getPosition().x);
	this->m_transform->translateY(this->rigitBody->getPosition().y);
}

void Player::draw()
{
	this->spriteAnimation->render(this->m_transform->x, this->m_transform->y);
}

void Player::dispose()
{
	this->spriteAnimation->dispose();
}
