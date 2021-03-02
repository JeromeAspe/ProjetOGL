#pragma once
#include "Object.h"
#include "GameObject.h"

class Component : public Object
{
protected:
	GameObject* gameObject;
public:
	Component();
	Component(GameObject* _gameObject);
	~Component();

	GameObject* GetGameObject();
};

