#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>

#include <common/entity.h>

class Scene
{
public:

  Scene();
  ~Scene();

  std::vector<Entity*> Entities() { return entities; };

  void AddEntity(Entity* entity) { entities.push_back(entity); };

private:

  std::vector<Entity*> entities;

};

#endif
