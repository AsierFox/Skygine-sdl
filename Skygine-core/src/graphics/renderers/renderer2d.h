#pragma once

#include "renderable2d.h"

namespace stormengine
{
	namespace graphics
	{

		class Renderer2D
		{
		protected:
			virtual void submit(const Renderable2D* const renderable) = 0;
			virtual void flush() = 0;
		};

	}
}
