#pragma once
#include "GameObject.h"
#include "SphereCollider.h"

class Sphere : public GameObject
{
protected:
	SphereCollider* collider = nullptr;

public :
#pragma region Constructors
	Sphere(Renderer* _renderer, Transform* _transform);
	Sphere(Renderer* _renderer, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
	Sphere(std::string _texturePath, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
#pragma endregion

#pragma region Getters
	SphereCollider* GetCollider();
#pragma endregion 

#pragma region Destructors
	~Sphere();
#pragma endregion
};

