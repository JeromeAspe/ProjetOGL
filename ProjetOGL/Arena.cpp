#include "Arena.h"
#include "Engine.h"

Arena::Arena() {
	GenerateArena();
}
Arena::~Arena() {
}

void Arena::GenerateArena() {
	Renderer* _renderer = new Renderer(Engine::GetInstance()->GetTextureID(), "uvmap.DDS");

	

	arenaObjects.push_back(new GameObject("cube.obj", _renderer, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(ARENA_SIZE, 0.01f, ARENA_SIZE)));
	arenaObjects.push_back(new GameObject("cube.obj", _renderer, glm::vec3(ARENA_SIZE, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1, ARENA_WALL_HEIGHT, ARENA_SIZE)));
	arenaObjects.push_back(new GameObject("cube.obj", _renderer, glm::vec3(-ARENA_SIZE, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1, ARENA_WALL_HEIGHT, ARENA_SIZE)));
	arenaObjects.push_back(new GameObject("cube.obj", _renderer, glm::vec3(0, 0, ARENA_SIZE), glm::vec3(0, 0, 0), glm::vec3(ARENA_SIZE, ARENA_WALL_HEIGHT, 1)));
	arenaObjects.push_back(new GameObject("cube.obj", _renderer, glm::vec3(0, 0, -ARENA_SIZE), glm::vec3(0, 0, 0), glm::vec3(ARENA_SIZE, ARENA_WALL_HEIGHT, 1)));
}