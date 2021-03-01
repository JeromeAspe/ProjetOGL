#pragma once
#include <GLFW/glfw3.h>
#include <common/texture.hpp>
#include <string>

class Renderer
{
protected:
	GLuint textureID = 0;
	GLuint texture = 0;
	

public :

#pragma region Constructors

	Renderer(GLuint _textureID, GLuint _texture);
	Renderer(GLuint _textureID, std::string _name);

#pragma endregion

#pragma region Getters

	GLuint GetTextureID();

	GLuint GetTexture();

#pragma endregion


};

