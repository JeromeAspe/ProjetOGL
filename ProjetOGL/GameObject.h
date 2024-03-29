#pragma once
#include "Object.h"
#include "Renderer.h"
#include "Transform.h"
#include <common/objloader.hpp>

class GameObject : public Object
{
protected:
	std::string objectPath = "";
	Renderer* renderer = nullptr;
	Transform* transform = nullptr;
	int indexEngine = -1;

	
public:
#pragma region Constructors
	GameObject(std::string _objectPath,Renderer* _renderer,Transform* _transform);
	GameObject(std::string _objectPath,Renderer* _renderer,const glm::vec3& _position, const glm::vec3& _rotation, const  glm::vec3& _scale);
	GameObject(std::string _objectPath, std::string _texturePath, const glm::vec3& _position, const glm::vec3& _rotation, const  glm::vec3& _scale);
	
#pragma endregion

#pragma region Destructors
	~GameObject();
#pragma endregion 

#pragma region Getters
	Renderer* GetRenderer();
	Transform* GetTransform();
	int GetIndexEngine();
#pragma endregion

	virtual void Update(const GLuint& _matrixID);
	//TODO 
	void AddComponent();
};

