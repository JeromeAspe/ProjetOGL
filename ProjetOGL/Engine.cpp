#include "Engine.h"
GLFWwindow* window;
Engine* Engine::instance = nullptr;
Engine::Engine() {
	
	instance = this;
	Init();
}
Engine::~Engine() {
	for (size_t i = 0; i < monobehaviours.size(); i++) {
		if (!monobehaviours[i]) continue;
		monobehaviours[i]->OnDestroy();
	}
	monobehaviours.clear();
	for (size_t i = 0; i < gameobjects.size(); i++) {
		if (!gameobjects[i]) continue;
		delete(gameobjects[i]);
	}
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete(window);
}

void Engine::Init()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Tutorial 07 - Model Loading", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	// Create and compile our GLSL program from the shaders
	programID = LoadShaders("TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader");
	textureID = glGetUniformLocation(programID, "myTextureSampler");
}

void Engine::Update()
{
		matrixID = glGetUniformLocation(programID, "MVP");
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
		gameobjects[i]->Update(matrixID);
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

void Engine::AddCollider(Collider* _collider)
{
	colliders.push_back(_collider);
}

void Engine::RemoveGameObject(int& _index)
{
	 //TODO
}

GLuint& Engine::GetTextureID()
{
	return textureID;
}

GLFWwindow* Engine::GetWindow()
{
	return window;
}

Engine* Engine::GetInstance()
{
	if (!instance)
		instance = new Engine();
	return instance;
}