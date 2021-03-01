#include "GameObject.h"

GameObject::GameObject( std::string _objectPath, Renderer* _renderer, Transform* _transform) : Object()
{
	objectPath = _objectPath;
	renderer = _renderer;
	transform = _transform;
}

GameObject::GameObject( std::string _objectPath, Renderer* _renderer, glm::vec3 _position, glm::vec4 _rotation, glm::vec3 _scale) : Object()
{
	objectPath = _objectPath;
	renderer = _renderer;
	transform = new Transform(_position,_rotation,_scale);
}

GameObject::~GameObject()
{
	delete(renderer);
	delete(transform);
}

Renderer* GameObject::GetRenderer()
{
	return renderer;
}

Transform* GameObject::GetTransform()
{
	return transform;
}
