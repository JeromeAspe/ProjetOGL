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
	//Init();
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

GLuint& Renderer::GetVerticesBuffer()
{
	return verticesBuffer;
}

GLuint& Renderer::GetUvBuffer()
{
	return uvBuffer;
}

GLuint& Renderer::GetNormalsBuffer()
{
	return normalsBuffer;
}

void Renderer::Update()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(textureID, 0);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STREAM_DRAW);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);;
	// 3rd attribute buffer : Normals
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, normalsBuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
