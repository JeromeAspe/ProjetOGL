#include "Transform.h"

Transform::Transform(glm::vec3 _position, glm::vec4 _rotation, glm::vec3 _scale)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

void Transform::SetPosition(glm::vec3 _position)
{
}

void Transform::SetRotation(glm::vec4 _rotation)
{
	rotation = _rotation;
}

void Transform::SetScale(glm::vec3 _scale)
{
	scale = _scale;
}

