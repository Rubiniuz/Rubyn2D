#include <common/core.h>

int main()
{
  Core core;

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
        break;
      default:
        break;
    }
    ent.SetPosition(playerpos);
    core.Run();
  }

  return 0;
}
