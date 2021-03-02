#include "Renderer.h"


Renderer::Renderer(GLuint& _textureID, GLuint& _texture)
{
	textureID = _textureID;
	texture = _texture;
}

Renderer::Renderer(GLuint& _textureID, std::string _name)
{
	textureID = _textureID;
	texture = loadDDS(_name.c_str());
	Init();
}

void Renderer::Init()
{
	glGenBuffers(1, &verticesBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalsBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
}

GLuint& Renderer::GetTextureID()
{
	return textureID;
}

GLuint& Renderer::GetTexture()
{
	return texture;
}

std::vector<glm::vec3>& Renderer::GetVertices()
{
	return vertices;
}

std::vector<glm::vec2>& Renderer::GetUvs()
{
	return uvs;
}

std::vector<glm::vec3>& Renderer::GetNormals()
{
	return normals;
}
