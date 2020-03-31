#ifndef GAME_H
#define GAME_H

#include <common/scene.h>

class Game : public Scene
{
public:
  Game();
  ~Game();

  virtual void Update(sf::Event event);
  
private:

};

#endif
