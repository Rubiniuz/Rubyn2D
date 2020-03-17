#include <common/entity.h>

int Entity::nextGlobalID = 0;

Entity::Entity() : sf::Drawable(), sf::Transformable()
{
  globalID = nextGlobalID;
  nextGlobalID++;

  parent = nullptr;

  globalPos = sf::Vector2f(0.0f,0.0f);
  localPos = sf::Vector2f(0.0f,0.0f);

  globalScale = sf::Vector2f(1.0f,1.0f);
  localScale = sf::Vector2f(1.0f,1.0f);

  globalRot = 0.0f;
  localRot = 0.0f;
}

Entity::~Entity()
{

}

void Entity::SetPosition(sf::Vector2f position)
{
  /*
  // position
  sprite.setPosition(position); // absolute position
  sprite.move(0.0f,0.0f); // offset relative to the current position
  */
  localPos = position;
  globalPos = localPos;
  sprite.setPosition(localPos);
  if (parent != nullptr)
  {
    sprite.setPosition(parent->globalPos);
    sprite.move(localPos);
    globalPos = parent->globalPos + localPos;
  }

  std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		(*child)->SetPosition((*child)->localPos);
	}
}

void Entity::SetRotation(float rotation)
{
  // rotation
  sprite.setRotation(rotation); // absolute angle
  sprite.rotate(rotation / 6); // offset relative to the current angle
}

void Entity::SetScale(sf::Vector2f scaling)
{
  /*
  // scale
  sprite.setScale(scaling); // absolute scale factor
  sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
  */
  localScale = scaling;
  globalScale = localScale;
  sprite.setScale(localScale);
  if (parent != nullptr)
  {
    sprite.setScale(parent->globalScale);
    sprite.scale(localScale);
    globalScale = sf::Vector2f(parent->globalScale.x * localScale.x, parent->globalScale.y * localScale.y);
  }

  std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		(*child)->SetScale((*child)->localScale);
	}
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


void Entity::LoadFromFile(std::string fromFile)
{
  if (_texture.loadFromFile(fromFile))
  {
    std::cout << "Loaded Texture: " << fromFile << std::endl;
  }
}

void Entity::Init()
{
  sprite.setTexture(_texture);
  std::cout << "Made a sprite from Texture." << std::endl;
  sprite.setOrigin(sf::Vector2f(_texture.getSize().x / 2, _texture.getSize().y / 2));
  sprite.setColor(_color);
}

void Entity::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
  target.draw(sprite, states);
}
