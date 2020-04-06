#include "Enemy.h"

Enemy::Enemy(std::string id, std::string name, int x, int y)
	: Entity(id, name, x, y)
{
	this->m_speed = 3.0f;

	this->m_currentAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 2, 2, 4, 3, 3);
}

void Enemy::setCollidernRegion()
{
	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };
}

void Enemy::update(float delta)
{
	this->m_currentAnimation->update();

	this->m_rigitBody->update(delta);

	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);

	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };
}

void Enemy::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
	TextureManager::getInstance()->renderRect(this->m_collider);
}

void Enemy::dispose()
{
}