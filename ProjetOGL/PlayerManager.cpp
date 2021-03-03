#include "PlayerManager.h"

PlayerManager* PlayerManager::instance = new PlayerManager();

PlayerManager::PlayerManager() {

}
PlayerManager::~PlayerManager() {

}

PlayerManager* PlayerManager::Instance()
{
	return instance;
}

void PlayerManager::Add(TransformSync* _sync)
{
	players.push_back(_sync);
}

void PlayerManager::UpdatePosition(int _id, glm::vec3 _pos)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		/*if(players[i].ID == _id)
			player[i].Posititon = _pos*/
	}
}

