#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>

#include <common/entity.h>

class Scene : public Entity
{
public:

  Scene();
  ~Scene();

private:

  Entity* bgLayer;
  Entity* entLayer;
  Entity* uiLayer;

};

#endif
