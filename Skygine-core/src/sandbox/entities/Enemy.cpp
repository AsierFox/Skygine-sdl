#include "Enemy.h"

Enemy::Enemy(std::string id, std::string name, int x, int y, TiledMap* map)
	: Entity(id, name, x, y, map)
{
	this->m_idleAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 2, 2, 4, 3, 3);

	this->m_currentAnimation = this->m_idleAnimation;

	this->m_origin = new Point(x + (this->m_currentAnimation->getWidth() / 2), y + (this->m_currentAnimation->getHeight() / 2));

	this->m_speed = 1.0f;

	this->aStar = new AStarFinding(map);
}

void Enemy::setColliderRegion()
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

	this->checkCollisions(delta);

	this->m_currentAnimation->update();
}

void Enemy::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);

	if (aStar->isGoalFounded())
	{
		SDL_Rect nextStepRect = { this->nextCell.x * this->belongsToMap->getTileSize(), this->nextCell.y * this->belongsToMap->getTileSize(),
			this->belongsToMap->getTileSize(), this->belongsToMap->getTileSize() };
	}
}

void Enemy::dispose()
{
	delete this->aStar;
}

void Enemy::interact(GameObject* other)
{
}

void Enemy::proximityInteract(GameObject* other)
{
}

void Enemy::updatePathFinding(Entity* target)
{
	if (aStar->isGoalFounded()
		&& (target->getMapCellCoordX() != aStar->getGoalCell()->m_xCoord
		|| target->getMapCellCoordY() != aStar->getGoalCell()->m_yCoord))
	{
		aStar->reset();
	}

	aStar->findPath(this->getMapCellCoords(), target->getMapCellCoords());

	if (aStar->isGoalFounded())
	{
		if (aStar->isGoalReached())
		{
			this->m_rigitBody->removeForce();
		}
		else
		{
			this->nextCell = aStar->nextPathPosition(this);

			Point* targetPosition = new Point(
				(this->nextCell.x * this->belongsToMap->getTileSize()) + (this->belongsToMap->getTileSize() / 2),
				(this->nextCell.y * this->belongsToMap->getTileSize()) + (this->belongsToMap->getTileSize() / 2));

			if (this->m_origin->x < targetPosition->x)
			{
				this->m_rigitBody->setForceX(this->m_speed);
			}
			else if (this->m_origin->x > targetPosition->x)
			{
				this->m_rigitBody->setForceX(-this->m_speed);
			}

			if (this->m_origin->y < targetPosition->y)
			{
				this->m_rigitBody->setForceY(this->m_speed);
			}
			else if (this->m_origin->y > targetPosition->y)
			{
				this->m_rigitBody->setForceY(-this->m_speed);
			}
		}
	}
}

void Enemy::checkCollisions(float delta)
{
	this->m_lastSafePosition.y = this->m_transform->y;
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);

	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };
	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);

	for (int i = 0; i < this->belongsToMap->getColliders().size(); i++)
	{
		SDL_Rect mapCollider = this->belongsToMap->getColliders()[i];

		if (CollisionHandler::getInstance()->checkCollision(this->m_collider, mapCollider))
		{
			this->m_transform->y = this->m_lastSafePosition.y;
			break;
		}
	}


	this->m_lastSafePosition.x = this->m_transform->x;
	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);

	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getWidth() / 2);

	for (int i = 0; i < this->belongsToMap->getColliders().size(); i++)
	{
		SDL_Rect mapCollider = this->belongsToMap->getColliders()[i];

		if (CollisionHandler::getInstance()->checkCollision(this->m_collider, mapCollider))
		{
			this->m_transform->x = this->m_lastSafePosition.x;
			break;
		}
	}
}
