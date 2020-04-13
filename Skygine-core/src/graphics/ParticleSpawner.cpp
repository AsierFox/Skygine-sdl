#include "ParticleSpawner.h"

ParticleSpawner* ParticleSpawner::s_instance = nullptr;

ParticleSpawner::ParticleSpawner()
{
	
}

ParticleSpawner* ParticleSpawner::getInstance()
{
	if (nullptr == ParticleSpawner::s_instance)
	{
		ParticleSpawner::s_instance = new ParticleSpawner;
	}

	return ParticleSpawner::s_instance;
}

void ParticleSpawner::loadParticles(ParticleType type, int quantity)
{
	switch (type)
	{
	case ParticleType::WIND:
	{
		SpriteSheetRegion* sprite = new SpriteSheetRegion(WindParticle::s_textureId, WindParticle::s_resourcePath, 2, 1, 4, 4);

		for (int i = 0; i < quantity; i++)
		{
			this->m_generatedParticles.push_back(new WindParticle(sprite,
				Transform(MathUtils::getRandomNumber(0, 200), MathUtils::getRandomNumber(0, 200)),
				Vector2D(3, 3),
				1000));
		}

		spdlog::debug("[ParticleSpawner::loadParticles] '{0}' of type {1} created!", quantity, type);
		break;
	}
	default:
		spdlog::debug("[ParticleSpawner::loadParticles] The particle '{0}' is not implemented yet!", type);
		break;
	}
}

void ParticleSpawner::update(float dt)
{
	// Don't add it++ on loop when we erase an element
	for (std::vector<Particle*>::iterator it = this->m_generatedParticles.begin(); it != this->m_generatedParticles.end(); )
	{
		Particle* particle = (*it);

		if (particle->isDead())
		{
			it = this->m_generatedParticles.erase(it);
		}
		else
		{
			particle->update(dt);
			++it;
		}
	}
}

void ParticleSpawner::render()
{
	for (Particle* particle : this->m_generatedParticles)
	{
		particle->render();
	}
}

void ParticleSpawner::dispose()
{
}
