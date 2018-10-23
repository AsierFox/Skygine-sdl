#include "shader.h"

namespace stormengine
{
	namespace graphics
	{

		Shader::Shader(const char* vertexPath, const char* fragmentPath)
			:
			m_vertexPath(vertexPath),
			m_fragmentPath(fragmentPath)
		{
			m_id = load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_id);
		}

		void Shader::setUniform1i(const GLchar* name, int value)
		{
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniform1f(const GLchar* name, float value)
		{
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const GLchar* name, const Vect2& vector)
		{
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}

		void Shader::setUniform3f(const GLchar* name, const Vect3& vector)
		{
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}

		void Shader::setUniform4f(const GLchar* name, const Vect4& vector)
		{
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}

		void Shader::setUniformMatr4f(const GLchar* name, const Matr4& matrix)
		{
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		void Shader::enable() const
		{
			glUseProgram(m_id);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}

		GLuint Shader::getId() const
		{
			return m_id;
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertexFileContent = FileUtils::read_file(m_vertexPath);
			std::string fragmentFileContent = FileUtils::read_file(m_fragmentPath);

			const char* vertexSource = vertexFileContent.c_str();
			const char* fragmentSource = fragmentFileContent.c_str();

			GLint compileResult;

			// Generate vertex shader
			glShaderSource(vertex, 1, &vertexSource, NULL);
			glCompileShader(vertex);

			glGetShaderiv(vertex, GL_COMPILE_STATUS, &compileResult);
			if (GL_FALSE == compileResult)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);

				std::vector<char> errors(length);
				glGetShaderInfoLog(vertex, length, &length, &errors[0]);
				std::cout << "Error loading vertex shader: " << std::endl;
				std::cout << &errors[0] << std::endl;

				glDeleteShader(vertex);

				return 0;
			}

			// TODO: Refactor duplicated code

			// Generata fragment shader
			glShaderSource(fragment, 1, &fragmentSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &compileResult);
			if (GL_FALSE == compileResult)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);

				std::vector<char> errors(length);
				glGetShaderInfoLog(fragment, length, &length, &errors[0]);
				std::cout << "Error loading fragment shader: " << std::endl;
				std::cout << &errors[0] << std::endl;

				glDeleteShader(fragment);

				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		GLint Shader::getUniformLocation(const GLchar* name)
		{
			return glGetUniformLocation(getId(), name);
		}

	}
}
