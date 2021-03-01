#pragma once
#include <string>
#include "MonoBehaviour.h"
#include "GameObject.h"

class Player : public MonoBehaviour
{
private: 
	std::string nickname = "";
	float playerSpeed = 1;
public:
	Player();
	Player(GameObject _gameObject);
	Player(std::string _nickname, float _speed);
	Player(std::string _nickname, float _speed, GameObject _gameObject);
	~Player();
};

