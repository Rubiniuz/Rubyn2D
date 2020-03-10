#include <common/scene.h>

Scene::Scene() : Entity()
{
  bgLayer = new Entity();
  entLayer = new Entity();
  uiLayer = new Entity();
  this->AddChild(bgLayer);
  this->AddChild(entLayer);
  this->AddChild(uiLayer);
}

Scene::~Scene()
{
  delete(bgLayer);
  delete(entLayer);
  delete(uiLayer);
}
