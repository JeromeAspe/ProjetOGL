#include "Engine.h"

Engine* Engine::instance = nullptr;
Engine::Engine() {
	
	instance = this;
}
Engine::~Engine() {
	for (size_t i = 0; i < monobehaviours.size(); i++) {
		if (!monobehaviours[i]) continue;
		monobehaviours[i]->OnDestroy();
	}
	monobehaviours.clear();
	//OnDestroy Objects
	delete(window);
}

void Engine::Update(GLFWwindow* _window, GLuint& _programID)
{

	window = _window;
	programID = _programID;
	MatrixID = glGetUniformLocation(programID, "MVP");
	UpdateBehaviours();
	UpdateObjects();
}

void Engine::UpdateBehaviours() {
	for (size_t i = 0; i < monobehaviours.size(); i++) {
		if (!monobehaviours[i]) continue;
		monobehaviours[i]->Update();
	}
}
void Engine::UpdateObjects()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (int i = 0; i < gameobjects.size(); i++) {
		glUseProgram(programID);
		gameobjects[i]->Update(MatrixID);
	}
	glfwSwapBuffers(window);
	glfwPollEvents();
}
void Engine::AddMonoBehaviours(MonoBehaviour* _behaviour, int & _index) {
	_behaviour->Start();
	monobehaviours.push_back(_behaviour);
	_index = monobehaviours.size();
}

void Engine::RemoveMonoBehaviour(int& _index) {
	monobehaviours[_index]->OnDestroy();
}

void Engine::AddGameObject(GameObject* _object, int& _index)
{
	
	gameobjects.push_back(_object);
	_index = gameobjects.size();
}

void Engine::RemoveGameObject(int& _index)
{
	 //TODO
}

Engine* Engine::GetInstance()
{
	if (!instance)
		instance = new Engine();
	return instance;
}