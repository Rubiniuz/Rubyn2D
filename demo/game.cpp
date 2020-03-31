#include "game.h"

sf::Vector2f playerpos = sf::Vector2f(150.0f, 250.0f);
float rotation = 0.0f;

Entity ent;
Entity ent2;

Game::Game() : Scene()
{
    ent.LoadFromFile("assets/cool-arrow.png");
    ent.Init();
    ent.SetColor(80,146,222,255);
    ent.SetPosition(playerpos);
    ent.SetScale(sf::Vector2f(2.0f,2.0f));
    ent.SetRotation(rotation);

    layers[1]->AddChild(&ent);

    ent2.LoadFromFile("assets/cool-arrow.png");
    ent2.Init();
    ent2.SetColor(80,146,222,255);
    ent2.SetPosition(sf::Vector2f(50.0f,50.0f));
    ent2.SetScale(sf::Vector2f(2.0f,2.0f));

    ent.AddChild(&ent2);

    ent.SetScale(sf::Vector2f(2.0f,2.0f));
}

Game::~Game()
{

}

void Game::Update(sf::Event event)
{
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
  rotation += 0.005f;
  ent.SetRotation(rotation);
  ent.SetPosition(playerpos);
}
