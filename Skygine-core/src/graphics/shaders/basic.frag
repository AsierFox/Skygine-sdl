#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_position;

in DATA
{
	vec4 position;
	vec4 color;
} fragmentShader_in;

void main()
{
	float intensity = 1.0 / length(fragmentShader_in.position.xy - light_position);
	color = fragmentShader_in.color * intensity;
}
