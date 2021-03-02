#pragma once
#include <vector>
#include "MonoBehaviour.h"

class Engine
{
private:
	std::vector<MonoBehaviour*> monobehaviours;
	std::vector<GameObject*> gameobjects;
	GLuint programID ;
	GLuint MatrixID;
	GLFWwindow* window = nullptr;
	static Engine* instance;
public:
	Engine();
	~Engine();

	void Update(GLFWwindow* _window, GLuint& _programID);
	void UpdateBehaviours();
	void UpdateObjects();
	void AddMonoBehaviours(MonoBehaviour* _behaviour, int& _index);
	void RemoveMonoBehaviour(int& _index);
	void AddGameObject(GameObject* _object, int& _index);
	void RemoveGameObject(int& _index);

	static Engine* GetInstance();
};

