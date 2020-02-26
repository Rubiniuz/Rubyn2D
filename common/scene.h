#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>

#include <common/sprite.h>

class Scene
{
public:

  Scene();
  ~Scene();

  std::vector<sf::Shape*> Shapes() { return shapes; };

  void AddShape(sf::Shape* shape) { shapes.push_back(shape); };

private:

  std::vector<Sprite*> sprites;
  std::vector<sf::Shape*> shapes;


};

#endif
