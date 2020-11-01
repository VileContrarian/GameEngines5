#version 330  core

in vec3 Normal;
in vec2 TexCoords;
in vec3 Colour;

out vec4 Vector4;

void main(){
	Vector4 = vec4(Colour, 0.0f);
}