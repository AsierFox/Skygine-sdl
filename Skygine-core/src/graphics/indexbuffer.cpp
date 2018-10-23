#include "indexbuffer.h"

namespace stormengine
{
	namespace graphics
	{

		IndexBuffer::IndexBuffer(GLushort* data, const GLsizei indexCount)
			:
			m_indexCount(indexCount)
		{
			glGenBuffers(1, &m_id);
			bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(GLushort), data, GL_STATIC_DRAW);
			unbind();
		}

		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		}

		void IndexBuffer::unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		GLuint IndexBuffer::getIndexCount() const
		{
			return m_indexCount;
		}

	}
}
