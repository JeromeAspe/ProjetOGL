#include "Component.h"

Component::Component() : Object(){}
Component::Component(GameObject* _gameObject) : Object() {
	gameObject = _gameObject;
}
Component::~Component()
{ 
	delete(gameObject);
}

GameObject* Component::GetGameObject() { return gameObject; }