#version 330 core
out vec4 FragColor;

in vec2 texcoord;

uniform sampler2D sprite;

void main()
{
	FragColor = texture(sprite, texcoord);
}