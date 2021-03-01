#pragma once
#include "Object.h"
#include "Renderer.h"
#include "Transform.h"

class GameObject : public Object
{
protected:
	std::string objectPath = "";
	Renderer* renderer = nullptr;
	Transform* transform = nullptr;
public:
#pragma region Constructors
	GameObject(std::string _objectPath,Renderer* _renderer,Transform* _transform);
	GameObject(std::string _objectPath,Renderer* _renderer,glm::vec3 _position,glm::vec4 _rotation, glm::vec3 _scale);
	
#pragma endregion

#pragma region Destructors
	~GameObject();
#pragma endregion 

#pragma region Getters
	Renderer* GetRenderer();
	Transform* GetTransform();
#pragma endregion
	//TODO 
	void AddComponent();
};

