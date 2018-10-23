#include "buffer.h"

namespace stormengine
{
	namespace graphics
	{

		Buffer::Buffer(GLfloat* data, const GLsizei count, const GLuint componentCount)
			:
			m_componentCount(componentCount)
		{
			glGenBuffers(1, &m_id);
			bind();
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			unbind();
		}

		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_id);
		}

		void Buffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		GLuint Buffer::getComponentCount() const
		{
			return m_componentCount;
		}

	}
}
