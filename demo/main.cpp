#include <common/core.h>

int main()
{
  Core core;
  //Network* network = new Network();

  core.CreateWindow();

  Scene test;

  sf::Vector2f playerpos = sf::Vector2f(50.0f, 50.0f);

  Entity ent;

  ent.LoadFromFile("assets/Player.png");
  ent.Init();
  ent.SetColor(80,146,222,255);
  ent.SetPosition(playerpos);
  ent.SetScale(sf::Vector2f(1.0f,1.0f));

  test.AddChild(&ent);

  Entity ent2;

  ent2.LoadFromFile("assets/Player.png");
  ent2.Init();
  ent2.SetColor(80,146,222,255);
  ent2.SetPosition(playerpos);
  ent2.SetScale(sf::Vector2f(2.0f,2.0f));

  ent.AddChild(&ent2);

  Entity ent3;

  ent3.LoadFromFile("assets/Player.png");
  ent3.Init();
  ent3.SetColor(80,146,222,255);
  ent3.SetPosition(playerpos);
  ent3.SetScale(sf::Vector2f(1.0f,1.0f));

  ent2.AddChild(&ent3);

  ent2.SetScale(sf::Vector2f(2.0f,2.0f));

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
