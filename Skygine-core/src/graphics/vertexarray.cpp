#include "vertexarray.h"

namespace stormengine
{
	namespace graphics
	{

		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &m_id);
		}

		VertexArray::~VertexArray()
		{
			int buffersSize = m_buffers.size();
			for (int i = 0; i < buffersSize; i++)
			{
				delete m_buffers[i];
			}
		}

		void VertexArray::addBuffer(Buffer* buffer, GLuint location)
		{
			bind();
			buffer->bind();

			glEnableVertexAttribArray(location);
			// Add attrs to vertex
			glVertexAttribPointer(
				location, // layout (location = @{location}) in vec4 position;
				buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			buffer->unbind();
			unbind();


		}

		void VertexArray::bind() const
		{
			glBindVertexArray(m_id);
		}

		void VertexArray::unbind() const
		{
			glBindVertexArray(0);
		}

	}
}
