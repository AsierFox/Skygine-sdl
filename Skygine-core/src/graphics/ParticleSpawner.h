#pragma once

#include <vector>

#include <spdlog/spdlog.h>

#include "particles/Particle.h"
#include "particles/ParticleType.h"
#include "particles/WindParticle.h"
#include "SpriteSheetRegion.h"
#include "../utils/MathUtils.h"

class ParticleSpawner
{
	static ParticleSpawner* s_instance;

	std::vector<Particle*> m_generatedParticles;

	ParticleSpawner();

public:

	static ParticleSpawner* getInstance();

	void loadParticles(ParticleType type, int quantity);
	void loadParticles(ParticleType type, int quantity, bool isLoop);

	void update(float dt);
	void render();

	void dispose();
};
