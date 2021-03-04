#include "Sphere.h"
#include "Engine.h"

Sphere::Sphere(Renderer* _renderer, Transform* _transform) : GameObject("Sphere.obj", _renderer, _transform)
{
	collider = new SphereCollider(this);
	Engine::GetInstance()->AddCollider(collider);
}

Sphere::Sphere(Renderer* _renderer, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : GameObject("Sphere.obj", _renderer, _position, _rotation, _scale)
{
	collider = new SphereCollider(this);
	Engine::GetInstance()->AddCollider(collider);
}

Sphere::Sphere(std::string _texturePath, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : GameObject("Sphere.obj", _texturePath, _position, _rotation, _scale)
{
	collider = new SphereCollider(this);
	Engine::GetInstance()->AddCollider(collider);
}

SphereCollider* Sphere::GetCollider()
{
	return collider;
}

Sphere::~Sphere()
{
	delete(collider);
}

void Sphere::Update(const GLuint& _matrixID)
{
	transform->UpdateTransform(_matrixID);
	collider->UpdateBounds();
	renderer->Update();
}
