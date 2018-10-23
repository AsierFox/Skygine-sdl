#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../utils/fileutils.h"
#include "../maths/matr4.h"
#include "../maths/vect2.h"
#include "../maths/vect3.h"
#include "../maths/vect4.h"

using namespace stormengine;
using namespace utils;
using namespace maths;

namespace stormengine
{
	namespace graphics
	{

		class Shader
		{
			GLuint m_id;
			const char* m_vertexPath;
			const char* m_fragmentPath;
		public:
			Shader(const char* vertexPath, const char* fragmentPath);
			~Shader();

			void setUniform1i(const GLchar* name, int value);
			void setUniform1f(const GLchar* name, float value);
			void setUniform2f(const GLchar* name, const Vect2& vector);
			void setUniform3f(const GLchar* name, const Vect3& vector);
			void setUniform4f(const GLchar* name, const Vect4& vector);
			void setUniformMatr4f(const GLchar* name, const Matr4& matrix);

			void enable() const;
			void disable() const;

			GLuint getId() const;
		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};
	}
}
