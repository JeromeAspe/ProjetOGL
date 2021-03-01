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
	Transform(const glm::vec3& _position, const glm::vec4& _rotation, const glm::vec3& _scale);
#pragma endregion

#pragma region Getters

	glm::vec3& GetPosition();

	glm::vec4& GetRotation();

	glm::vec3& GetScale();
#pragma endregion

#pragma region Setters
	virtual void SetPosition(const glm::vec3& _position);

	virtual void SetRotation(const glm::vec4& _rotation);

	virtual void SetScale(const glm::vec3& _scale);

#pragma endregion
};

