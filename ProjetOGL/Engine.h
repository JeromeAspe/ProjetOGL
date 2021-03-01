#pragma once
#include <vector>
#include "MonoBehaviour.h"

class Engine
{
private:
	std::vector<MonoBehaviour*> monobehaviours;
	static Engine* instance;
public:
	Engine();
	~Engine();

	void Update();
	void AddMonoBehaviours(MonoBehaviour* _behaviour, int& _index);
	void RemoveMonoBehaviour(int& _index);

	static Engine* GetInstance();
};

