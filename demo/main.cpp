#include <common/core.h>
#include "game.h"

int main()
{
  Core core;

  core.CreateWindow();

  Game* game = new Game();

  core.AddScene("Game", game);

  core.Start();

  sf::Event event;

  while(core.isRunning)
  {
    event = core.GetEventHandler();

    core.Run(event);
  }

  return 0;
}
