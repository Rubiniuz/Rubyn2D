#include <common/entity.h>

int Entity::nextGlobalID = 0;

Entity::Entity() : sf::Drawable(), sf::Transformable()
{
  globalID = nextGlobalID;
  nextGlobalID++;

  parent = nullptr;
}

Entity::~Entity()
{

}

void Entity::SetPosition(sf::Vector2f position)
{
  // position
  sprite.setPosition(position); // absolute position
  sprite.move(0.0f,0.0f); // offset relative to the current position
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

void Entity::AddChild(Entity* child)
{
  if(child->parent != nullptr)
  {
    child->parent->RemoveChild(child);
  }
  child->parent = this;
  this->children.push_back(child);
}

void Entity::RemoveChild(Entity* child)
{
  std::vector<Entity*>::iterator it = children.begin();
  while(it != children.end())
  {
    if((*it)->globalID == child->globalID)
    {
      child->parent = nullptr;
      it = children.erase(it);
    }
    else
    {
      ++it;
    }
  }
}

Entity* Entity::GetChild(unsigned int i)
{
  if (i < children.size()) {
		return children[i];
	}
	return nullptr;
}

void Entity::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
  target.draw(sprite, states);
}
