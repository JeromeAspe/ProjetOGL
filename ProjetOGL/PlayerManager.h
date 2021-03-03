#pragma once
#include "TransformSync.h"
#include <iostream>
#include <vector>

class PlayerManager
{
private:
	static PlayerManager* instance;
	PlayerManager();
	~PlayerManager();
	PlayerManager(const PlayerManager&) {};
	PlayerManager& operator=(const PlayerManager&) {};
protected:
	std::vector<TransformSync*> players;

public:
	static PlayerManager* Instance();
	void Add(TransformSync* _sync);
	void UpdatePosition(int _id, glm::vec3 _pos);


};

