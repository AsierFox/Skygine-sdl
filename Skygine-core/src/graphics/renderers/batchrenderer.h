#pragma once

#include "renderer2d.h"

namespace stormengine
{
	namespace graphics
	{

		class BatchRenderer2D : Renderer2D {
			//
		public:
			void submit(const Renderable2D* const renderable) override;
			void flush() override;
		};

	}
}
