#include <common/core.h>
#include "network.h"
#include "spacewar.h"

int main()
{
  Core core;
  //Network* network = new Network();

  core.CreateWindow();

  Scene test;

  sf::Vector2f playerpos = sf::Vector2f(150.0f, 150.0f);

  Entity ent;

  ent.LoadFromFile("assets/Player.png");
  ent.Init();
  ent.SetColor(80,146,222,255);
  ent.SetPosition(playerpos);

  test.AddEntity(&ent);

  core.AddScene(&test);

  core.Start();

  sf::Event event;

  while(core.isRunning)
  {
    event = core.GetEventHandler();
    switch(event.type)
    {
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::D)
        {
          playerpos.x += 5;
        }
        if (event.key.code == sf::Keyboard::A)
        {
          playerpos.x -= 5;
        }
        if (event.key.code == sf::Keyboard::W)
        {
          playerpos.y -= 2.5f;
        }
        if (event.key.code == sf::Keyboard::S)
        {
          playerpos.y += 2.5f;
        }
        break;
      default:
        break;
    }
    ent.SetPosition(playerpos);
    core.Run();
  }

  return 0;
}
