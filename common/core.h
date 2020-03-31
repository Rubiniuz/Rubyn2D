#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <common/scene.h>
#include <common/entity.h>

class Core
{
public:
  Core();
  ~Core();

  void CreateWindow();

  void Start();

  void Run(sf::Event event);

  void Render(sf::Drawable* toRender);

  void Clear();

  void Draw(Entity* entity);

  bool isRunning;

  sf::Event GetEventHandler() { return eventHandler; };

  void AddScene(std::string sceneName, Scene* toAdd);

  Scene* GetScene(std::string sceneName);

  void GoToScene(std::string sceneName);

private:

  void CheckWindowState();

  sf::RenderWindow window;
  sf::VideoMode currentMode;
  sf::Event eventHandler;

  std::map<std::string, Scene*> scenes;
  Scene* currentScene;

};

#endif /* CORE_H */
