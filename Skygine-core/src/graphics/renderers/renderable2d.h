#pragma once

#include "../../maths/vect2.h"
#include "../../maths/vect3.h"
#include "../../maths/vect4.h"

#include "../vertexarray.h"
#include "../buffer.h"
#include "../indexbuffer.h"
#include "../shader.h"

using namespace stormengine;
using namespace maths;

namespace stormengine
{
	namespace graphics
	{

		class Renderable2D
		{
		protected:
			Vect3 m_position;
			Vect2 m_size;
			Vect4 m_color;

			VertexArray* m_vertexArray;
			IndexBuffer* m_indexBuffer;

			Shader& m_shader;
		public:
			Renderable2D(Vect3 position, Vect2 size, Vect4 color, Shader& shader);
			~Renderable2D();

			const Vect3& getPosition() const;
			const Vect2& getSize() const;
			const Vect4& getColor() const;

			const VertexArray* getVertexArray() const;
			const IndexBuffer* getIndexBuffer() const;

			Shader& getShader() const;
		};
	}
}
