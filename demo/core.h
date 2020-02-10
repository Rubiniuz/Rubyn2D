#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Core
{
public:
  Core();
  ~Core();

  void CreateWindow();

  void Run();

  void Render(sf::Shape* toRender);

  void Clear();

  bool isRunning;

  sf::Event GetEventHandler() { return eventHandler; };

private:

  sf::RenderWindow window;
  sf::VideoMode currentMode;
  sf::Event eventHandler;

};

#endif /* CORE_H */
