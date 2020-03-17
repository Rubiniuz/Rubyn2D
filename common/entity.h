#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Drawable, public sf::Transformable
{
public:

  Entity();
  ~Entity();

  sf::Texture Texture() { return _texture; };
  sf::Sprite Sprite() { return sprite; };
  sf::Color Color() { return _color; };

  void SetColor(sf::Color color) { _color = color; };
  void SetColor(int r, int g, int b, int a) { _color = sf::Color(r,g,b,a); };

  void LoadFromFile(std::string fromFile) ;
  void Init();

  void Draw(sf::RenderTarget& target,sf::RenderStates states){draw(target,states);};

  void SetPosition(sf::Vector2f position);
  void SetRotation(float rotation);
  void SetScale(sf::Vector2f scaling);

  sf::Vector2f Position() { return sf::Vector2f(_position.x,_position.y); };
  float Rotation() { return localRot; };
  sf::Vector2f Scale() { return sf::Vector2f(_scale.x,_scale.y); };

  Entity* Parent() { return parent; };
  int GlobalID() { return globalID; };

  std::vector<Entity*> Children() { return children; };

  void AddChild(Entity* child);
  void RemoveChild(Entity* child);

  Entity* GetChild(unsigned int i);

  sf::Vector2f Point1,Point2;
  sf::Color Colour;

  sf::Sprite sprite;

  sf::Vector2f globalPos;
  sf::Vector2f globalScale;
  float globalRot;

  sf::Vector2f localPos;
  sf::Vector2f localScale;
  float localRot;

private:

  virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;

  sf::Texture _texture;

  sf::Color _color;

  glm::vec3 _position;
  glm::vec3 _scale;
  glm::vec3 _rotation;

  std::vector<Entity*> children;

  int globalID;
  static int nextGlobalID;

  Entity* parent;

};

#endif
