#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Transformable
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

  void Draw(sf::RenderTarget& target,sf::Transform transform){draw(target,transform);};

  void SetPosition(sf::Vector2f position);
  void SetRotation(float rotation);
  void SetScale(sf::Vector2f scaling);

  sf::Vector2f Position() { return _position; };
  float Rotation() { return _rotation; };
  sf::Vector2f Scale() { return _scale; };

  Entity* Parent() { return parent; };
  int GlobalID() { return globalID; };

  std::vector<Entity*> Children() { return children; };

  void AddChild(Entity* child);
  void RemoveChild(Entity* child);

  Entity* GetChild(unsigned int i);

  sf::Sprite sprite;

private:

  void draw(sf::RenderTarget& target, sf::Transform parentTransform)const;
  virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;

  sf::Texture _texture;

  sf::Color _color;

  sf::Vector2f _position;
  sf::Vector2f _scale;
  float _rotation;
  sf::Transform _transform;

  std::vector<Entity*> children;

  int globalID;
  static int nextGlobalID;

  Entity* parent;

};

#endif
