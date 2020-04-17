#include <common/core.h>
#include "game.h"

int main()
{
  Game* game = new Game();

  Core core;

  //core.CreateWindow();

  //game->Initialize();

  //core.AddScene("Game", game);

  //core.Start();

  sf::Event event;

  while(core.isRunning)
  {
    event = core.GetEventHandler();

    //core.Run(event);
    game->ClientUpdate();
  }


  return 0;
}
