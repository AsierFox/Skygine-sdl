#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 projection_matrix;
uniform mat4 viewport_matrix = mat4(1.0);
uniform mat4 model_matrix = mat4(1.0);

out DATA
{
	vec4 position;
	vec4 color;
} vertexShader_out;

void main()
{
	gl_Position = projection_matrix * viewport_matrix * model_matrix * position;
	vertexShader_out.position = model_matrix * position;
	vertexShader_out.color = color;
}
