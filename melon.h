#pragma once
#include "Polycode.h"
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"
#include "player.h"

using namespace Polycode;

class MelonApp {
public:
    MelonApp(PolycodeView *view);
    ~MelonApp();
    bool Update();

private:
	Core *core;
  PhysicsScene *scene;
  Player* player;
};
