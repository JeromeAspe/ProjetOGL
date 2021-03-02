#pragma once
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <common/texture.hpp>
#include <string>
#include <vector>

class Renderer
{
protected:
	GLuint textureID = 0;
	GLuint texture = 0;
	
	GLuint verticesBuffer = 0;
	GLuint uvBuffer = 0;
	GLuint normalsBuffer = 0;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

public :

#pragma region Constructors

	Renderer(GLuint& _textureID, GLuint& _texture);
	Renderer(GLuint& _textureID, std::string _name);

	void Init();
#pragma endregion

#pragma region Getters

	GLuint& GetTextureID();

	GLuint& GetTexture();

	std::vector<glm::vec3>& GetVertices();
	std::vector<glm::vec2>& GetUvs();
	std::vector<glm::vec3>& GetNormals();

#pragma endregion


};

