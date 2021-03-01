#pragma once
#include "GameObject.h"
#include "BoxCollider.h"

class Cube : public GameObject
{
protected:
	BoxCollider* collider = nullptr;

public :

#pragma region Constructors
	Cube(std::string _objectPath, Renderer* _renderer, Transform* _transform);
	Cube(std::string _objectPath, Renderer* _renderer, glm::vec3 _position, glm::vec4 _rotation, glm::vec3 _scale);
#pragma endregion

#pragma region Getters
	BoxCollider* GetCollider();
#pragma endregion
#pragma region Destructors
	~Cube();
#pragma endregion


};
