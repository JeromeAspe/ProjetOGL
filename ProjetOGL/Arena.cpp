#include "Arena.h"
#include "Engine.h"
#include "Cube.h"

Arena::Arena() {
	GenerateArena();
}
Arena::~Arena() {
}

void Arena::GenerateArena() {
	Renderer* _renderer = new Renderer(Engine::GetInstance()->GetTextureID(), "raimbow.DDS");

	

	arenaObjects.push_back(new Cube(_renderer, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(ARENA_SIZE, 0.01f, ARENA_SIZE)));
	arenaObjects.push_back(new Cube(_renderer, glm::vec3(ARENA_SIZE, 0, 0), glm::vec3(0, 0, 0), glm::vec3(ARENA_WALL_WIDTH, ARENA_WALL_HEIGHT, ARENA_SIZE + ARENA_WALL_WIDTH)));
	arenaObjects.push_back(new Cube(_renderer, glm::vec3(-ARENA_SIZE, 0, 0), glm::vec3(0, 0, 0), glm::vec3(ARENA_WALL_WIDTH, ARENA_WALL_HEIGHT, ARENA_SIZE + ARENA_WALL_WIDTH)));
	arenaObjects.push_back(new Cube(_renderer, glm::vec3(0, 0, ARENA_SIZE), glm::vec3(0, 0, 0), glm::vec3(ARENA_SIZE + ARENA_WALL_WIDTH, ARENA_WALL_HEIGHT, ARENA_WALL_WIDTH)));
	arenaObjects.push_back(new Cube(_renderer, glm::vec3(0, 0, -ARENA_SIZE), glm::vec3(0, 0, 0), glm::vec3(ARENA_SIZE + ARENA_WALL_WIDTH, ARENA_WALL_HEIGHT, ARENA_WALL_WIDTH)));
}