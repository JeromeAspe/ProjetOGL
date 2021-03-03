#pragma once
#include "MonoBehaviour.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/objloader.hpp>

class Engine
{
private:

	std::vector<MonoBehaviour*> monobehaviours;
	std::vector<GameObject*> gameobjects;
	GLuint programID;
	GLuint matrixID;
	GLuint textureID;
	//GLFWwindow* window = nullptr;
	static Engine* instance;
	GLuint vertexArrayID;
public:
	Engine();
	~Engine();

	void Init();
	void Update();
	void UpdateBehaviours();
	void UpdateObjects();
	void AddMonoBehaviours(MonoBehaviour* _behaviour, int& _index);
	void RemoveMonoBehaviour(int& _index);
	void AddGameObject(GameObject* _object, int& _index);
	void RemoveGameObject(int& _index);
	GLuint& GetTextureID();
	GLFWwindow* GetWindow();

	static Engine* GetInstance();
};

