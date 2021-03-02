#include "Transform.h"
using namespace glm;

#include <common/controls.hpp>

Transform::Transform(const glm::vec3& _position, const glm::vec3& _rotation, const glm::vec3& _scale)
{
	m_position = _position;
	m_rotation = _rotation;
	m_scale = _scale;
}

glm::vec3& Transform::GetPosition()
{
	return m_position;
}

glm::vec3& Transform::GetRotation()
{
	return m_rotation;
}

glm::vec3& Transform::GetScale()
{
	return m_scale;
}

void Transform::SetPosition(const glm::vec3&  _position)
{
	m_position = _position;
}

void Transform::SetRotation(const glm::vec3&  _rotation)
{
	m_rotation = _rotation;
}

void Transform::SetScale(const glm::vec3&  _scale)
{
	m_scale = _scale;
}

void Transform::UpdateTransform(const GLuint& _matrixID)
{
	computeMatricesFromInputs();
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	MVP = glm::translate(MVP, m_position);
	MVP = glm::rotate<float>(MVP, 1.59f, m_rotation);
	MVP = glm::scale(MVP, m_scale);

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &MVP[0][0]);
}

void Transform::Translate(const glm::vec3& _position) {
	m_position = _position;
}
void Transform::Rotate(const glm::vec3& _rotation) {
	m_rotation = _rotation;
}
void Transform::Scale(const glm::vec3& _scale) {
	m_scale = _scale;
}

