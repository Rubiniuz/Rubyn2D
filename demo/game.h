#ifndef GAME_H
#define GAME_H

#include <common/scene.h>
#include <common/client.h>
#include <common/server.h>

class Game : public Scene
{
public:
  Game();
  ~Game();

  void Initialize();

  int port;

  int updatenumber;

  Client client;

  sf::Vector2f prevPosition;

  virtual void Update(sf::Event event);

private:

};

#endif
