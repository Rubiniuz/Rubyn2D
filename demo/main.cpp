#include <common/core.h>
#include "network.h"
#include "spacewar.h"

int main()
{
  Core* core = new Core();
  //Network* network = new Network();

  core->CreateWindow();

  sf::RectangleShape rect;
  rect.setSize(sf::Vector2f(200.f, 300.f));
  sf::Vector2f playerpos = sf::Vector2f(150.0f, 150.0f);

  rect.setPosition(playerpos);
  rect.setFillColor(sf::Color::Blue);

  sf::Event event;

  while(core->isRunning)
  {
    core->Run();
    event = core->GetEventHandler();
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
    rect.setPosition(playerpos);
    core->Clear();
    core->Render(&rect);
  }
  return 0;
}
