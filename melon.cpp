#include "melon.h"
#include "Polycode.h"
#include "PolycodeView.h"
#include "level.h"

MelonApp::MelonApp(PolycodeView *view) {
  core = new POLYCODE_CORE(view, 640, 480, false, true, 0, 0, 90, 0, true);

	CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

  scene = new PhysicsScene();
  //scene->setGravity(Vector3(0, -0.1, 0));

  //ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 10, 10);
  //ground->loadTexture("Resources/green_texture.png");
  //scene->addPhysicsChild(ground, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
/*
  for(int i=0; i < 10; i++) {
    ScenePrimitive *box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 0.8,0.8,0.8);
    box->setColor(0.0, 0.0, 1.0, 1.0);
    box->Roll(-45 + (rand() % 90));
    box->Pitch(-45 + (rand() % 90));
    box->setPosition(-2 + (rand() % 4), i*0.5, -2 + (rand() % 4));
    scene->addPhysicsChild(box, PhysicsSceneEntity::SHAPE_BOX, 1.0);
  }
*/
  Level::loadLevel("level/test.dae", scene);

	player = new Player();
	player->loadTexture("Resources/pink_texture.png");
	player->addToScene(scene);
	player->setPosition(Vector3(1, 5, 1));

  scene->getDefaultCamera()->setPosition(-5, 9, -5);
  scene->getDefaultCamera()->lookAt(Vector3(0, 0, 0));
}

MelonApp::~MelonApp() {
  delete scene;
  delete player;
  delete core;
}

bool MelonApp::Update() {
  scene->getDefaultCamera()->setPosition(player->getPosition() + Vector3(-5, 9, -5));
  return core->updateAndRender();
}

int main(int argc, char *argv[]) {
  PolycodeView *view = new PolycodeView("Hello Polycode!");
  MelonApp *app = new MelonApp(view);
  while(app->Update()) {}
  delete app;
  delete view;
  return 0;
}
