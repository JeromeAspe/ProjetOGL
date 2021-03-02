#include "Sphere.h"

Sphere::Sphere(std::string _objectPath, Renderer* _renderer, Transform* _transform) : GameObject(_objectPath, _renderer, _transform)
{
	collider = new SphereCollider();
}

Sphere::Sphere(std::string _objectPath, Renderer* _renderer, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : GameObject(_objectPath, _renderer, _position, _rotation, _scale)
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
