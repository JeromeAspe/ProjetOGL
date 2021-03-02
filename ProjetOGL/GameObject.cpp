#include "GameObject.h"

GameObject::GameObject( std::string _objectPath, Renderer* _renderer, Transform* _transform) : Object()
{
	objectPath = _objectPath;
	renderer = _renderer;
	transform = _transform;
	loadOBJ(_objectPath.c_str(), _renderer->GetVertices(), _renderer->GetUvs(), _renderer->GetNormals());
	
}

GameObject::GameObject( std::string _objectPath, Renderer* _renderer, const glm::vec3& _position, const glm::vec4& _rotation, const glm::vec3& _scale) : Object()
{
	objectPath = _objectPath;
	renderer = _renderer;
	transform = new Transform(_position,_rotation,_scale);
	loadOBJ(_objectPath.c_str(), _renderer->GetVertices(), _renderer->GetUvs(), _renderer->GetNormals());
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

void GameObject::Update()
{
	//Transform Update
	renderer->Update();
}
