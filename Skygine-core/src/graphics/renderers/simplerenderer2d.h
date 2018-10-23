#pragma once

#include <deque>
#include <GL/glew.h>

#include "renderer2d.h"

namespace stormengine
{
	namespace graphics
	{

		/* Simple 2D renderer where we need 1 drawable per renderable
		 * which is not efficient.
		 */
		class SimpleRenderer2D : Renderer2D
		{
			std::deque<const Renderable2D*> m_renderQueue;
		public:
			void submit(const Renderable2D* const renderable) override;
			void flush() override;
		};

	}
}
