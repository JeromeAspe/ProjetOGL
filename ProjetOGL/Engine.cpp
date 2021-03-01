#include "Engine.h"

Engine::Engine() {}
Engine::~Engine() {
	for (size_t i = 0; i < monobehaviours.size(); i++) {
		if (!monobehaviours[i]) continue;
		monobehaviours[i]->OnDestroy();
	}
	monobehaviours.clear();
}

void Engine::Update() {
	for (size_t i = 0; i < monobehaviours.size(); i++) {
		if (!monobehaviours[i]) continue;
		monobehaviours[i]->Update();
	}
}
void Engine::AddMonoBehaviours(MonoBehaviour* _behaviour, int & _index) {
	_behaviour->Start();
	monobehaviours.push_back(_behaviour);
	_index = monobehaviours.size();
}

void Engine::RemoveMonoBehaviour(int& _index) {
	monobehaviours[_index]->OnDestroy();
}

Engine* Engine::GetInstance()
{
	if (!instance)
		instance = new Engine();
	return instance;
}