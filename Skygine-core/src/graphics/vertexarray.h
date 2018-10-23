#pragma once

#include <vector>
#include <GL/glew.h>

#include "buffer.h"

namespace stormengine
{
	namespace graphics
	{

		/* Used to send all the buffers data to the shader.
		 */
		class VertexArray
		{
			GLuint m_id;
			std::vector<Buffer*> m_buffers;
		public:
			VertexArray();
			~VertexArray();

			/* Method to change location of vertex,
			 * layout (location = @{location}) in vec4 position;
			 */
			void addBuffer(Buffer* buffer, GLuint location);

			void bind() const;
			void unbind() const;
		};

	}
}
