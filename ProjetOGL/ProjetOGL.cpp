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

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/objloader.hpp>

//#include "GameObject.h"
#include "Engine.h"

int main( void )
{
	
	Engine* _engine = new Engine();
	Renderer* _renderer = new Renderer(_engine->GetTextureID(), "uvmap.DDS");
	GameObject* _a = new GameObject("cube.obj", _renderer, vec3(1, 0, 0), vec3(1, 0, 0), vec3(1, 1, 1));
	GameObject* _b = new GameObject("cube.obj", _renderer, vec3(-1, 0, 0), vec3(1, 0, 0), vec3(1, 1, 1));
	
	_engine->Update();
		
	glfwTerminate();

	return 0;
}

