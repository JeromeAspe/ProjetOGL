#pragma once
#include "Sphere.h"
#include <iostream>
#include <vector>

class PlayerManager
{
private:
	static PlayerManager instance;
	PlayerManager();
	~PlayerManager();
	PlayerManager(const PlayerManager&) {};
	PlayerManager& operator=(const PlayerManager&) {};
protected:
	std::vector<Sphere*> players;

public:
	static PlayerManager& Instance();
	void UpdatePosition(glm::vec3 _pos);


};

