#include "GameObject.h"
#include "Engine.h"


GameObject::GameObject( std::string _objectPath, Renderer* _renderer, Transform* _transform) : Object()
{
	Engine::GetInstance()->AddGameObject(this, indexEngine);
	objectPath = _objectPath;
	renderer = _renderer;
	transform = _transform;
	loadOBJ(_objectPath.c_str(), _renderer->GetVertices(), _renderer->GetUvs(), _renderer->GetNormals());
	
}

GameObject::GameObject( std::string _objectPath, Renderer* _renderer, const glm::vec3& _position, const glm::vec3& _rotation, const glm::vec3& _scale) : Object()
{
	Engine::GetInstance()->AddGameObject(this, indexEngine);
	objectPath = _objectPath;
	renderer = _renderer;
	
	transform = new Transform(_position,_rotation,_scale);
	loadOBJ(_objectPath.c_str(), _renderer->GetVertices(), _renderer->GetUvs(), _renderer->GetNormals());
	renderer->Init();
}

GameObject::GameObject(std::string _objectPath, std::string _texturePath, const glm::vec3& _position, const glm::vec3& _rotation, const glm::vec3& _scale)
{
	Engine::GetInstance()->AddGameObject(this, indexEngine);
	objectPath = _objectPath;
	renderer = new Renderer(Engine::GetInstance()->GetTextureID(),_texturePath);

	transform = new Transform(_position, _rotation, _scale);
	loadOBJ(_objectPath.c_str(), renderer->GetVertices(), renderer->GetUvs(), renderer->GetNormals());
	renderer->Init();
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

int GameObject::GetIndexEngine()
{
	return indexEngine;
}

void GameObject::Update(const GLuint& _matrixID)
{
	transform->UpdateTransform(_matrixID);
	renderer->Update();
}
