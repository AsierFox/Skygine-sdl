#include "Player.h"

Player::Player(std::string id, std::string name, int x, int y, TiledMap* map)
	: Entity(id, name, x, y, map)
{
	this->m_speed = 3.0f;
	this->m_maxJumpTime = 15.0f;
	this->m_jumpTime = this->m_maxJumpTime;
	this->m_JumpForce = 10.0f;
	this->m_isJumpling = false;
	this->m_maxAttackTime = 10.0f;
	this->m_attackTime = this->m_maxAttackTime;
	this->m_isAttacking = false;

	this->m_idleAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 1, 2, 4, 3, 3);
	this->m_walkAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 3, 4, 4, 3, 3);
	this->m_currentAnimation = this->m_idleAnimation;

	this->m_origin = new Point(x + (this->m_currentAnimation->getWidth() / 2), y + (this->m_currentAnimation->getHeight() / 2));

	// TODO Load for the collision handler the map

	setColliderRegion();
}

void Player::setColliderRegion()
{
	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };
}

void Player::update(float delta)
{
	this->input(delta);

	this->m_rigitBody->update(delta);
	
	this->checkCollisions(delta);
	
	this->updateAnimationState();
	
	this->m_currentAnimation->update();
}

void Player::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
}

void Player::dispose()
{
	// TODO Dispose Sprites
}

void Player::interact(GameObject* other)
{
}

void Player::proximityInteract(GameObject* other)
{
}

void Player::input(float delta)
{
	this->m_rigitBody->removeForce();

	if (!this->m_isAttacking)
	{
		if (InputHandler::getInstance()->isAxisKeyDown(AxisDirection::RIGHT))
		{
			this->m_rigitBody->setForceX(this->m_speed);
		}

		if (InputHandler::getInstance()->isAxisKeyDown(AxisDirection::LEFT))
		{
			this->m_rigitBody->setForceX(-this->m_speed);
		}

		if (InputHandler::getInstance()->isAxisKeyDown(AxisDirection::UP))
		{
			this->m_rigitBody->setForceY(-this->m_speed);
		}

		if (InputHandler::getInstance()->isAxisKeyDown(AxisDirection::DOWN))
		{
			this->m_rigitBody->setForceY(this->m_speed);
		}
	}

	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		this->m_isJumpling = true;
		this->m_rigitBody->setForceY(-this->m_speed * this->m_JumpForce);
	}

	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_SPACE) && this->m_isJumpling && this->m_jumpTime > 0)
	{
		this->m_jumpTime -= delta;
		this->m_rigitBody->setForceY(-this->m_speed * this->m_JumpForce);
	}
	else {
		this->m_isJumpling = false;
		this->m_jumpTime = this->m_maxJumpTime;
	}

	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_E))
	{
		this->m_rigitBody->removeForce();
		this->m_isAttacking = true;
	}

	if (this->m_isAttacking && this->m_attackTime > 0)
	{
		this->m_attackTime -= delta;
	}
	else {
		this->m_isAttacking = false;
		this->m_attackTime = this->m_maxAttackTime;
	}

}

void Player::checkCollisions(float delta)
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

void Player::updateAnimationState()
{
	if (this->m_rigitBody->getForce().x != 0 || this->m_rigitBody->getForce().y != 0)
	{
		this->m_currentAnimation = m_walkAnimation;
	}
	else
	{
		this->m_currentAnimation = this->m_idleAnimation;
	}
}
