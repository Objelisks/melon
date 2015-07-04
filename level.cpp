#include "level.h"
#include <string>

SceneMesh* build_thing(String name) {
  if(name == "#Floor-mesh") {
    return new ScenePrimitive(ScenePrimitive::TYPE_BOX);
  }
  if(name == "#Wall-mesh") {
    return new ScenePrimitive(ScenePrimitive::TYPE_BOX);
  }
  if(name == "#Ramp-mesh") {
    SceneMesh* mesh = new ScenePrimitive(ScenePrimitive::TYPE_PLANE);
    mesh->setPitch(-45);
    mesh->setPosition(0, -0.1, 0);
    return mesh;
  }

  return new ScenePrimitive(ScenePrimitive::TYPE_BOX);
}

void Level::loadLevel(String file, PhysicsScene* scene) {
  Object levelFile;

  if(levelFile.loadFromXML("level/test.dae")) {
    printf("%s\n", "Loaded file");
  } else {
    printf("%s\n", "Failed to load level file");
    return;
  }

  // library_visual_scenes
    // visual_scene
      // foreach node
      // build SceneMesh from instance_geometry url

  //loadMeshes();

  // floors for now
  ObjectEntry* nodes = (*(levelFile.root["library_visual_scenes"]))["visual_scene"];
  // elements + attributes
  for(int i = 0; i < nodes->length+2; i++) {
    ObjectEntry* node = (*nodes)[i];
    if(node->name != "node") continue;

    String name = (*((*node)["instance_geometry"]))["url"]->stringVal;
    SceneMesh* entity = build_thing(name);
  	entity->loadTexture("Resources/green_texture.png");
    std::vector<String> transform = (*node)["matrix"]->stringVal.split(" ");
    Vector3 pos(-transform[3].toNumber(), transform[11].toNumber(), transform[7].toNumber());
    entity->Translate(pos);
    scene->addPhysicsChild(entity);
  }

  // get floors

  // get slopes

  // get walls

  // get items

  // get enemies

  // get player
}
