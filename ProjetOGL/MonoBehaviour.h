#pragma once
#include "Component.h"
#include "GameObject.h"
#include <iterator>

class MonoBehaviour : public Component
{
private :
	int indexEngine = -1;
public :
	MonoBehaviour();
	MonoBehaviour(GameObject* _gameObject);
	~MonoBehaviour();

	virtual void Start() {}
	virtual void Update() {}
	virtual void OnDestroy() {}
};

