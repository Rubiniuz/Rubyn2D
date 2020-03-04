#include <common/entity.h>

Entity::Entity() : sf::Drawable(), sf::Transformable()
{

}

Entity::~Entity()
{

}

void Entity::SetPosition(sf::Vector2f position)
{
  // position
  sprite.setPosition(position); // absolute position
  sprite.move(sf::Vector2f(position.x / 10, position.y)); // offset relative to the current position
}

void Entity::SetRotation(float rotation)
{
  // rotation
  sprite.setRotation(rotation); // absolute angle
  sprite.rotate(rotation / 6); // offset relative to the current angle
}

void Entity::SetScale(sf::Vector2f scaling)
{
  // scale
  sprite.setScale(scaling); // absolute scale factor
  sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
}

void Entity::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
  target.draw(sprite, states);
}
