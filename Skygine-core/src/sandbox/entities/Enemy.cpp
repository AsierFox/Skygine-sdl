#include "Enemy.h"

Enemy::Enemy(std::string id, std::string name, int x, int y, TiledMap* map)
	: Entity(id, name, x, y, map)
{
	this->m_speed = 3.0f;
	this->m_currentAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 2, 2, 4, 3, 3);

	this->m_origin = new Point(x + (this->m_currentAnimation->getWidth() / 2), y + (this->m_currentAnimation->getHeight() / 2));

	this->m_waittingTimeCount = 60.0f;
	this->m_waittingTime = 0;

	this->aStar = AStarFinding();
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
	this->m_rigitBody->update(delta);

	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);

	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };

	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getWidth() / 2);

	this->m_currentAnimation->update();

	//aStar.findPath(this->m_player->getMapCellCoords(), this->m_entities[0]->getMapCellCoords());

	//if (aStar.isGoalFounded())
	//{
	//	this->nextCell = aStar.nextPathPosition(this->m_player);
	//}
}

void Enemy::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
	TextureManager::getInstance()->renderRect(this->m_collider);

	SDL_Rect nextStepRect = { this->nextCell.x * (16 * 5), this->nextCell.y * (16 * 5), (16 * 5), (16 * 5) };
	TextureManager::getInstance()->renderRect(nextStepRect);
}

void Enemy::dispose()
{
}
