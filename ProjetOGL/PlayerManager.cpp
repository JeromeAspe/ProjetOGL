#include "PlayerManager.h"

PlayerManager PlayerManager::instance = PlayerManager();

PlayerManager::PlayerManager() {

}
PlayerManager::~PlayerManager() {

}

PlayerManager& PlayerManager::Instance()
{
	return instance;
}
