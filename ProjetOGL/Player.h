#pragma once
#include <string>
#include "MonoBehaviour.h"
#include "GameObject.h"
#include "Collider.h"

class Player : public MonoBehaviour
{
private: 
	std::string nickname = "";
	float playerSpeed = 2.0f;
	float frotemments = 0.1f;
	glm::vec3 speedVector = glm::vec3(0);
	Collider* collider = nullptr;
public:
	Player();
	Player(GameObject* _gameObject,Collider* _collider);
	Player(std::string _nickname, float _speed);
	Player(std::string _nickname, float _speed, GameObject* _gameObject);
	void Update();
	~Player();
};

