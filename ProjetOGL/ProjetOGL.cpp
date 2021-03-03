// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
//GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;


//#include "GameObject.h"
#include "Engine.h"
#include "Arena.h"
#include "Player.h"
#include "Sphere.h"
#include "Cube.h"
#include "TransformSync.h"
#include "PlayerManager.h"

#include "ENet.h"
#include <iostream>

int main( void )
{
	ENet* networkLayer = new ENet();

	if (!networkLayer->Initialize())
		return EXIT_FAILURE;

	std::cout << "Hello Enet!\n\n";
	std::cout << "press 1 for Client\n";
	std::cout << "press 2 for Server\n";

	char choice;
	std::cin >> choice;

	switch (choice)
	{
	case '1':
		networkLayer->SetupClient();
		networkLayer->ConnectClient();
		break;

	case '2':
		networkLayer->SetupServer();
		break;

	default:
		std::cout << "unknown choice !\n";
		break;

	}
	Engine* _engine = new Engine();
	//Renderer* _renderer = new Renderer(_engine->GetTextureID(), "raimbow.DDS");
	Cube* _b = new Cube("raimbow.DDS", vec3(-1, 0, 0), vec3(1, 0, 0), vec3(1, 1, 1));
	Sphere* _a = new Sphere("raimbow.DDS", vec3(1, 0, 0), vec3(1, 0, 0), vec3(0.25));

	Player* _player = new Player(_a);
	TransformSync* _sync = new TransformSync(true, networkLayer, _a);
	Arena* _arena = new Arena();
	do {
		_engine->Update();
		networkLayer->Update();
		PlayerManager::Instance()->UpdatePosition(1, vec3(0));
	}
	while (glfwGetKey(_engine->GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(_engine->GetWindow()) == 0);
	delete(networkLayer);
	glfwTerminate();

	return 0;
}

