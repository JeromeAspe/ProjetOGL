#include "Cube.h"

Cube::Cube(Renderer* _renderer, Transform* _transform) : GameObject("cube.obj", _renderer, _transform)
{
	collider = new BoxCollider();
}

Cube::Cube(Renderer* _renderer, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : GameObject("cube.obj", _renderer, _position, _rotation, _scale)
{
	collider = new BoxCollider();
}

BoxCollider* Cube::GetCollider()
{
	return collider;
}

Cube::~Cube()
{
	delete(collider);
}
