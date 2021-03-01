#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
protected:
	glm::vec3 position = glm::vec3(0);
	glm::vec4 rotation = glm::vec4(0);
	glm::vec3 scale = glm::vec3(0);

public:
#pragma region Constructors
	Transform(glm::vec3 _position, glm::vec4 _rotation, glm::vec3 _scale);
#pragma endregion

#pragma region Getters

	glm::vec3 GetPosition();

	glm::vec4 GetRotation();

	glm::vec3 GetScale();
#pragma endregion

#pragma region Setters
	virtual void SetPosition(glm::vec3 _position);

	virtual void SetRotation(glm::vec4 _rotation);

	virtual void SetScale(glm::vec3 _scale);

#pragma endregion
};

