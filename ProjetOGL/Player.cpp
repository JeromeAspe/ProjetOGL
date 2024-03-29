#include "Player.h"
#include "Engine.h"
#include <common/controls.hpp>
#include <iostream>

Player::Player() : MonoBehaviour() {}
Player::Player(GameObject* _gameObject, Collider* _collider) : MonoBehaviour(_gameObject) {

	collider = _collider;
}
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

	glm::vec3 _inputVector = getMovementVector();

	glm::vec3 _speedVector = glm::vec3(0);

	if (_inputVector.z == 1)
		_speedVector.z += 0.2f;
	else if (_inputVector.z == -1)
		_speedVector.z -= 0.2f;
	else if (_inputVector.z > -1 && _inputVector.z < 1 && speedVector.z != 0)
		_speedVector.z += speedVector.z > 0 ? -frotemments : frotemments;

	if (_inputVector.x == 1)
		_speedVector.x += 0.2f;
	else if (_inputVector.x == -1)
		_speedVector.x -= 0.2f;
	else if (_inputVector.x > -1 && _inputVector.x < 1 && speedVector.x != 0)
		_speedVector.x += speedVector.x > 0 ? -frotemments : frotemments;

	speedVector += _speedVector * 0.05f * playerSpeed;

	speedVector.x = glm::clamp(speedVector.x, -0.5f, 0.5f);
	speedVector.z = glm::clamp(speedVector.z, -0.5f, 0.5f);

	//speedVector += ((_inputVector * playerSpeed) * deltaTime);
	//speedVector -= (speedVector * frotemments);
	if (Engine::GetInstance()->IsInCollision(collider))
		speedVector = -speedVector * 1.f;
	glm::vec3 _finalPosition = gameObject->GetTransform()->GetPosition() + speedVector;

	gameObject->GetTransform()->SetFinalPosition(_finalPosition);



	SetCameraPosition(_finalPosition);
	lastTime = currentTime;
}
Player::~Player() 
{
	delete(collider);
}