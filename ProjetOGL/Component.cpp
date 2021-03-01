#include "Component.h"

Component::Component() : Object() { }
Component::Component(GameObject _gameObject) : Object() {
	gameObject = _gameObject;
}
Component::~Component() { }

GameObject Component::GetGameObject() { return gameObject; }