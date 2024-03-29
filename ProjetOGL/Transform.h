#pragma once
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
protected:
	glm::vec3 m_position = glm::vec3(0);
	glm::vec3 m_rotation = glm::vec3(0);
	glm::vec3 m_scale = glm::vec3(0);

	glm::vec3 m_finalPosition = glm::vec3(0);
	float m_t = 0;
public:
#pragma region Constructors
	Transform(const glm::vec3& _position, const glm::vec3& _rotation, const glm::vec3& _scale);
#pragma endregion

#pragma region Getters
	glm::vec3& GetPosition();
	glm::vec3& GetRotation();
	glm::vec3& GetScale();
	glm::vec3& GetFinalPosition();
#pragma endregion

#pragma region Setters
	virtual void SetPosition(const glm::vec3& _position);
	virtual void SetRotation(const glm::vec3& _rotation);
	virtual void SetScale(const glm::vec3& _scale);
	void Transform::SetFinalPosition(const glm::vec3& _finalPosition);
#pragma endregion

#pragma region Movements
	void UpdateTransform(const GLuint& _matrixID, float _t = 1);

	void Translate(const glm::vec3& _position);
	void Rotate(const glm::vec3& _rotation);
	void Scale(const glm::vec3& _scale);

	glm::vec3 LerpVector(const glm::vec3& _pos1, const glm::vec3& _pos2, float _t);

#pragma endregion

private:
	//glm::vec3 LerpPosition();
};

