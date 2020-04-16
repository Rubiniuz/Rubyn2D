#include "game.h"

sf::Vector2f playerpos = sf::Vector2f(150.0f, 250.0f);
float rotation = 0.0f;

Entity ent;
Entity ent2;

Game::Game() : Scene()
{
  client.Start();
}

Game::~Game()
{

}

void Game::Initialize()
{
  ent.LoadFromFile("assets/cool-arrow.png");
  ent.Init();
  ent.SetColor(80,146,222,255);
  ent.SetPosition(playerpos);
  ent.SetScale(sf::Vector2f(1.0f,1.0f));
  ent.SetRotation(rotation);

  layers[1]->AddChild(&ent);

  prevPosition = ent.getPosition();

  ent2.LoadFromFile("assets/cool-arrow.png");
  ent2.Init();
  ent2.SetColor(80,146,222,255);
  ent2.SetPosition(sf::Vector2f(50.0f,50.0f));
  ent2.SetScale(sf::Vector2f(1.0f,1.0f));

  layers[2]->AddChild(&ent2);
}

void Game::Update(sf::Event event)
{
  switch(event.type)
  {
    case sf::Event::KeyPressed:
      if (event.key.code == sf::Keyboard::D)
      {
        playerpos.y += 5;
      }
      if (event.key.code == sf::Keyboard::A)
      {
        playerpos.y -= 5;
      }
      if (event.key.code == sf::Keyboard::W)
      {
        playerpos.x += 2.5f;
      }
      if (event.key.code == sf::Keyboard::S)
      {
        playerpos.x -= 2.5f;
      }
      break;
    default:
      break;
  }
  ent.SetPosition(playerpos);
  if (updatenumber >= 50)
  {
    client.Run();
    updatenumber = 0;
  }
  updatenumber++;
}
