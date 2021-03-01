#pragma once
#include "Component.h"
#include "GameObject.h"

class MonoBehaviour : public Component
{
public :
	MonoBehaviour();
	MonoBehaviour(GameObject _gameObject);
	~MonoBehaviour();
};

