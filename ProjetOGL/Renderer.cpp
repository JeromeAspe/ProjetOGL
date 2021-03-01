#include "Renderer.h"

Renderer::Renderer(GLuint _textureID, GLuint _texture)
{
	textureID = _textureID;
	texture = _texture;
}

Renderer::Renderer(GLuint _textureID, std::string _name)
{
	textureID = _textureID;
	texture = loadDDS(_name.c_str());
}

GLuint Renderer::GetTextureID()
{
	return textureID;
}

GLuint Renderer::GetTexture()
{
	return texture;
}
