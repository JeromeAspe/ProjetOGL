#include "Transform.h"

Transform::Transform(glm::vec3 _position, glm::vec4 _rotation, glm::vec3 _scale)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

glm::vec3 Transform::GetPosition()
{
	return position;
}

glm::vec4 Transform::GetRotation()
{
	return rotation;
}

glm::vec3 Transform::GetScale()
{
	return scale;
}

void Transform::SetPosition(glm::vec3 _position)
{
	position = _position;
}

void Transform::SetRotation(glm::vec4 _rotation)
{
	rotation = _rotation;
}

void Transform::SetScale(glm::vec3 _scale)
{
	scale = _scale;
}

