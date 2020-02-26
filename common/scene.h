#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>

class Scene
{
public:

  Scene();
  ~Scene();

  std::vector<sf::Shape*> Shapes() { return shapes; };

  void AddShape(sf::Shape* shape) { shapes.push_back(shape); };

private:

  std::vector<sf::Shape*> shapes;


};

#endif
