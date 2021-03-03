#include "PlayerManager.h"
#include "Sphere.h"

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
		
		//printf("%d\n", players[i]->GetID());
		if (players[i]->GetID() == _id)
		{
			players[i]->UpdateElement(_pos);
			return;
		}
			
		
	}
	Sphere* _sphere = new Sphere("raimbow.DDS", glm::vec3(1, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0.25));
	TransformSync* _sync = new TransformSync(false,_id,players[0]->GetReseau(),_sphere);
	players.push_back(_sync);
}

