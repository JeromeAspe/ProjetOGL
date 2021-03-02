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
	speedVector += ((getMovementVector() * playerSpeed) / 144.0f);
	speedVector -= (speedVector * frotemments);
	glm::vec3 _finalPosition = gameObject->GetTransform()->GetPosition() + speedVector;
	gameObject->GetTransform()->SetPosition(_finalPosition);
}
Player::~Player() {

}