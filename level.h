#pragma once

#include "Polycode.h"
#include "Polycode3DPhysics.h"

using namespace Polycode;

class Level {
public:
  static void loadLevel(String file, PhysicsScene* scene);
};
