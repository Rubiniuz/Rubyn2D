#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <common/scene.h>

class Core
{
public:
  Core();
  ~Core();

  void CreateWindow();

  void Start();

  void Run();

  void Render(sf::Shape* toRender);

  void Clear();

  bool isRunning;

  sf::Event GetEventHandler() { return eventHandler; };

  void AddScene(Scene* toAdd) { scenes.push_back(toAdd); };

private:

  void CheckWindowState();

  sf::RenderWindow window;
  sf::VideoMode currentMode;
  sf::Event eventHandler;

  std::vector<Scene*> scenes;
  Scene* currentScene;

};

#endif /* CORE_H */
