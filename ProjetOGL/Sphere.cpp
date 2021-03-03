#include "Sphere.h"

Sphere::Sphere(Renderer* _renderer, Transform* _transform) : GameObject("Sphere.obj", _renderer, _transform)
{
	collider = new SphereCollider();
}

Sphere::Sphere(Renderer* _renderer, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : GameObject("Sphere.obj", _renderer, _position, _rotation, _scale)
{
	collider = new SphereCollider();
}

SphereCollider* Sphere::GetCollider()
{
	return collider;
}

Sphere::~Sphere()
{
	delete(collider);
}
