#pragma once
#include <vector>
#include "MonoBehaviour.h"

class Engine
{
private:
	std::vector<MonoBehaviour*> monobehaviours;
	std::vector<GameObject*> gameobjects;
	GLuint programID = 0;
	GLFWwindow* window = nullptr;
	static Engine* instance;
public:
	Engine(GLFWwindow* _window, GLuint _programID);
	~Engine();

	void Update();
	void UpdateBehaviours();
	void UpdateObjects();
	void AddMonoBehaviours(MonoBehaviour* _behaviour, int& _index);
	void RemoveMonoBehaviour(int& _index);

	static Engine* GetInstance();
};

