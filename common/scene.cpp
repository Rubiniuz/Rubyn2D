#include <common/scene.h>

Scene::Scene() : Entity()
{
  bgLayer = new Entity();
  entLayer = new Entity();
  uiLayer = new Entity();
  this->AddChild(bgLayer);
  layers.push_back(bgLayer);

  this->AddChild(entLayer);
  layers.push_back(entLayer);

  this->AddChild(uiLayer);
  layers.push_back(uiLayer);
}

Scene::~Scene()
{
  delete(bgLayer);
  delete(entLayer);
  delete(uiLayer);
}

void Scene::Update(sf::Event event)
{
  
}
