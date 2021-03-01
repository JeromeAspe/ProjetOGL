#include "Cube.h"

Cube::Cube(std::string _objectPath, Renderer* _renderer, Transform* _transform) : GameObject(_objectPath, _renderer, _transform)
{
	collider = new BoxCollider();
}

Cube::Cube(std::string _objectPath, Renderer* _renderer, glm::vec3 _position, glm::vec4 _rotation, glm::vec3 _scale) : GameObject(_objectPath, _renderer, _position, _rotation, _scale)
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
