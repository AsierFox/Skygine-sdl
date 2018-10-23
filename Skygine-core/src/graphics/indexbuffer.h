#pragma once

#include <GL/glew.h>

namespace stormengine
{
	namespace graphics
	{

		/* Class used to optimize buffer by omiting vertex to in common.
		 * This classes uses GL_ELEMENT_ARRAY_BUFFER instead of GL_ARRAY_BUFFER used in Buffer.
		 */
		class IndexBuffer
		{
			GLuint m_id;
			GLuint m_indexCount;
		public:
			IndexBuffer(GLushort* data, const GLsizei indexCount);

			void bind() const;
			void unbind() const;

			GLuint getIndexCount() const;
		};
	}
}
