#include "Player.h"

Player::Player(std::string id, std::string name, int x, int y)
	: GameObject(id, name, x, y)
{
	this->m_idleAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 1, 2, 4, 3, 3);
	this->m_walkAnimation = new SpriteAnimation(id, "assets/entities/nyson/nyson-sheet.png", 3, 4, 4, 3, 3);
	this->m_currentAnimation = this->m_idleAnimation;

	this->m_origin = new Point(x + (this->m_currentAnimation->getWidth() / 2), y + (this->m_currentAnimation->getHeight() / 2));

	this->m_rigitBody = new RigitBody();

	this->belongsToMap = TiledMapManager::getInstance()->getMap("test-map");

	setCollidernRegion();
}

void Player::setCollidernRegion()
{
	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };
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
	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);

	this->m_collider = {
			static_cast<int>(this->m_transform->x), static_cast<int>(this->m_transform->y),
			static_cast<int>(this->m_currentAnimation->getWidth()), static_cast<int>(this->m_currentAnimation->getHeight()) };

	// TODO Apply cam movement to the origin
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
	TextureManager::getInstance()->renderRect(this->m_collider.x, this->m_collider.y, this->m_collider.w, this->m_collider.h);


	for (int i = 0; i < this->belongsToMap->getColliders().size(); i++)
	{
		TextureManager::getInstance()->renderRect(this->belongsToMap->getColliders()[i].x, this->belongsToMap->getColliders()[i].y, this->belongsToMap->getColliders()[i].w, this->belongsToMap->getColliders()[i].h);

		if (CollisionHandler::getInstance()->checkCollision(this->m_collider, this->belongsToMap->getColliders()[i]))
		{
			spdlog::debug("MEW");
		}
	}
}

void Player::dispose()
{
	// TODO Dispose Sprites
}
