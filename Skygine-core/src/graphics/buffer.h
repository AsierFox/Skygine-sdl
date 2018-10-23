#pragma once

#include <GL/glew.h>

namespace stormengine
{
	namespace graphics
	{

		/* Class used to send the data to be drawn in the graphics card.
		 */
		class Buffer
		{
			GLuint m_id;
			GLuint m_componentCount;
		public:
			Buffer(GLfloat* data, const GLsizei count, const GLuint componentCount);

			void bind() const;
			void unbind() const;

			GLuint getComponentCount() const;
		};
	}
}
