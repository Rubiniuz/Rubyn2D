#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Drawable, sf::Transformable
{
public:

  Entity();
  ~Entity();

  sf::Texture Texture() { return _texture; };
  sf::Sprite Sprite() { return sprite; };
  sf::Color Color() { return _color; };

  void SetColor(sf::Color color) { _color = color; };
  void SetColor(int r, int g, int b, int a) { _color = sf::Color(r,g,b,a); };

  void LoadFromFile(std::string fromFile) { if (_texture.loadFromFile(fromFile)){ std::cout << "Loaded Texture: " << fromFile << std::endl; } };
  void Init() { sprite.setTexture(_texture); std::cout << "Made a sprite from Texture." << std::endl; sprite.setOrigin(sf::Vector2f(25.f, 25.f)); sprite.setColor(sf::Color(255, 0, 0, 255));};

  void Draw(sf::RenderTarget& target,sf::RenderStates states){draw(target,states);};

  void SetPosition(sf::Vector2f position);
  void SetRotation(float rotation);
  void SetScale(sf::Vector2f scaling);

  sf::Vector2f Point1,Point2;
  sf::Color Colour;

  sf::Sprite sprite;

private:

  virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;

  sf::Texture _texture;

  sf::Color _color;

  glm::vec3 _position;
  glm::vec3 _scale;
  glm::vec3 _rotation;

};

#endif
