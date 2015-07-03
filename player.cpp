#include "player.h"

const float playerSpeed = 0.05f;

Player::Player() : ScenePrimitive(ScenePrimitive::TYPE_BOX) {
  this->setColor(1.0, 1.0, 0.0, 1.0);
	CoreServices::getInstance()->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
	CoreServices::getInstance()->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);
}

void Player::addToScene(PhysicsScene* scene) {
  this->controller = scene->addCharacterChild(this, 10.0, 1.0, 0.5);
}

void Player::setPosition(Vector3 pos) {
  this->controller->warpCharacter(pos);
}

void Player::Update() {
  Vector3 move = Vector3(this->movement.x, 0.0, this->movement.y);
  move.Normalize();
  move = move * playerSpeed;
  this->controller->setWalkDirection(move);
}

void Player::handleEvent(Event* e) {
	if(e->getDispatcher() != CoreServices::getInstance()->getInput()) {
    return;
  }

	InputEvent* inputEvent = (InputEvent*)e;

	if(inputEvent->getEventCode() == InputEvent::EVENT_KEYDOWN) {
    switch (inputEvent->keyCode()) {
      case KEY_UP:
        this->movement.y = 1.0;
        break;
      case KEY_DOWN:
        this->movement.y = -1.0;
        break;
      case KEY_LEFT:
        this->movement.x = 1.0;
        break;
      case KEY_RIGHT:
        this->movement.x = -1.0;
        break;
    }
  } else if(inputEvent->getEventCode() == InputEvent::EVENT_KEYUP) {
    switch (inputEvent->key) {
      case KEY_UP:
      case KEY_DOWN:
        this->movement.y = 0.0;
        break;
      case KEY_LEFT:
      case KEY_RIGHT:
        this->movement.x = 0.0;
        break;
    }
  }
}
