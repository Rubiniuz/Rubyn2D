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

  layers[1]->AddChild(&ent2);
}

void Game::Update(sf::Event event)
{
  switch(event.type)
  {
    case sf::Event::KeyPressed:
      if (event.key.code == sf::Keyboard::D)
      {
        client.inputs[3] = true;
        std::cout << "D" << std::endl;
      }
      if (event.key.code == sf::Keyboard::A)
      {
        client.inputs[1] = true;
        std::cout << "A" << std::endl;
      }
      if (event.key.code == sf::Keyboard::W)
      {
        client.inputs[0] = true;
        std::cout << "W" << std::endl;
      }
      if (event.key.code == sf::Keyboard::S)
      {
        client.inputs[2] = true;
        std::cout << "S" << std::endl;
      }
      break;
    default:
      client.inputs[0] = false;
      client.inputs[1] = false;
      client.inputs[2] = false;
      client.inputs[3] = false;
      client.inputs[4] = false;
      break;
  }
  ClientUpdate();

  ent.SetPosition(client.playerPosition);
  ent2.SetPosition(client.enemyPosition);
}

void Game::ClientUpdate()
{
  client.Run();
}
