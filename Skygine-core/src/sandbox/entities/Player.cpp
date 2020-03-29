#include "Player.h"

Player::Player(std::string id, std::string name, int x, int y)
	: GameObject(id, name, x, y)
{
	this->spriteAnimation = new SpriteAnimation(id, "assets/nyson.png", 16, 24, 3);
}

void Player::update(float delta)
{
	this->spriteAnimation->update();
}

void Player::draw()
{
	this->spriteAnimation->render(this->m_transform->x, this->m_transform->y);
}

void Player::dispose()
{
	this->spriteAnimation->dispose();
}
