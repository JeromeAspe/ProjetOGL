#include "Cube.h"
#include "Engine.h"

Cube::Cube(Renderer* _renderer, Transform* _transform) : GameObject("cube.obj", _renderer, _transform)
{
	collider = new BoxCollider(this);
	Engine::GetInstance()->AddCollider(collider);
}

Cube::Cube(Renderer* _renderer, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : GameObject("cube.obj", _renderer, _position, _rotation, _scale)
{
	collider = new BoxCollider(this);
	Engine::GetInstance()->AddCollider(collider);
}

Cube::Cube(std::string _texturePath, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : GameObject("cube.obj",_texturePath,_position,_rotation,_scale)
{
	collider = new BoxCollider(this);
	Engine::GetInstance()->AddCollider(collider);
}

BoxCollider* Cube::GetCollider()
{
	return collider;
}

Cube::~Cube()
{
	delete(collider);
}
