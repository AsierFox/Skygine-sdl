#include "renderable2d.h"

namespace stormengine
{
	namespace graphics
	{

		Renderable2D::Renderable2D(Vect3 position, Vect2 size, Vect4 color, Shader& shader)
			:
			m_position(position),
			m_size(size),
			m_color(color),
			m_shader(shader)
		{
			m_vertexArray = new VertexArray;
			GLfloat vertices[] = {
				0, 0, 0,
				0, size.y, 0,
				size.y, size.y, 0,
				size.y, 0, 0 };
			GLfloat colors[] = {
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w };

			m_vertexArray->addBuffer(new Buffer(vertices, 3 * 4, 3), 0);
			m_vertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = {
				0, 1, 2,
				2, 3, 0 };
			m_indexBuffer = new IndexBuffer(indices, 6);
		}

		Renderable2D::~Renderable2D()
		{
			delete m_vertexArray;
			delete m_indexBuffer;
		}

		const Vect3& Renderable2D::getPosition() const
		{
			return m_position;
		}

		const Vect2& Renderable2D::getSize() const
		{
			return m_size;
		}

		const Vect4& Renderable2D::getColor() const
		{
			return m_color;
		}

		const VertexArray* Renderable2D::getVertexArray() const
		{
			return m_vertexArray;
		}

		const IndexBuffer* Renderable2D::getIndexBuffer() const
		{
			return m_indexBuffer;
		}

		Shader& Renderable2D::getShader() const
		{
			return m_shader;
		}

	}
}
