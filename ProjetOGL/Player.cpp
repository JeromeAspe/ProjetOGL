#include "Player.h"
#include <common/controls.hpp>

Player::Player() : MonoBehaviour() {}
Player::Player(GameObject* _gameObject) : MonoBehaviour(_gameObject) {}
Player::Player(std::string _nickname, float _speed) : MonoBehaviour() {
	nickname = _nickname;
	playerSpeed = _speed;
}
Player::Player(std::string _nickname, float _speed, GameObject* _gameObject) : MonoBehaviour(_gameObject) {
	nickname = _nickname;
	playerSpeed = _speed;
}
void Player::Update()
{
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);


	speedVector += ((getMovementVector() * playerSpeed) * deltaTime);
	speedVector -= (speedVector * frotemments);
	glm::vec3 _finalPosition = gameObject->GetTransform()->GetPosition() + speedVector;
	gameObject->GetTransform()->SetPosition(_finalPosition);


	lastTime = currentTime;
}
Player::~Player() {

}