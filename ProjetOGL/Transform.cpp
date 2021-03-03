#include "Transform.h"
using namespace glm;

#include <common/controls.hpp>


#include <GLFW/glfw3.h>


Transform::Transform(const glm::vec3& _position, const glm::vec3& _rotation, const glm::vec3& _scale)
{
	m_position = _position;
	m_finalPosition = _position;
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
glm::vec3& Transform::GetFinalPosition() {
	return m_finalPosition;
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

void Transform::SetFinalPosition(const glm::vec3& _finalPosition) { m_finalPosition = _finalPosition; };

void Transform::UpdateTransform(const GLuint& _matrixID, float _t)
{
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	computeMatricesFromInputs();
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	m_position = LerpVector(m_position, m_finalPosition, 0.1f);
	MVP = glm::translate(MVP, m_position);
	//MVP = glm::rotate<float>(MVP, 1.59f, m_rotation);
	MVP = glm::scale(MVP, m_scale);

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &MVP[0][0]);

	lastTime = currentTime;
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

glm::vec3 Transform::LerpVector(const glm::vec3& _pos1, const glm::vec3& _pos2, float _t) {
	//m_t += _t;
	//m_t = glm::clamp(m_t, 0.0f, 1.0f);

	float _x = _pos1.x + ((_pos2.x - _pos1.x) * _t);
	float _y = _pos1.y + ((_pos2.y - _pos1.y) * _t);
	float _z = _pos1.z + ((_pos2.z - _pos1.z) * _t);

	return glm::vec3(_x, _y, _z);
}

/*glm::vec3 Transform::LerpPosition() {
	

	glm::vec3 _pos = LerpVector(m_position, m_finalPosition, deltaTime * 10);

	
	return _pos;
}*/