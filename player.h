#pragma once
#include "Polycode.h"
#include "Polycode3DPhysics.h"

using namespace Polycode;

class Player : public ScenePrimitive {
public:
  Player();
  void Update();
  void addToScene(PhysicsScene* scene);
  void setPosition(Vector3 pos);
  void handleEvent(Event* e);

private:
  PhysicsCharacter* controller;
  Vector2 movement;
};
