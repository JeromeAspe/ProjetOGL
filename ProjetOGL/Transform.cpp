#include "Transform.h"

Transform::Transform(const glm::vec3& _position, const glm::vec4& _rotation, const glm::vec3& _scale)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

glm::vec3& Transform::GetPosition()
{
	return position;
}

glm::vec4& Transform::GetRotation()
{
	return rotation;
}

glm::vec3& Transform::GetScale()
{
	return scale;
}

void Transform::SetPosition(const glm::vec3&  _position)
{
	position = _position;
}

void Transform::SetRotation(const glm::vec4&  _rotation)
{
	rotation = _rotation;
}

void Transform::SetScale(const glm::vec3&  _scale)
{
	scale = _scale;
}

