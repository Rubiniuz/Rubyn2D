#include <common/entity.h>

int Entity::nextGlobalID = 0;

Entity::Entity() : sf::Transformable()
{
  globalID = nextGlobalID;
  nextGlobalID++;

  parent = nullptr;

  _position = sf::Vector2f(0.0f,0.0f);
  _scale = sf::Vector2f(1.0f,1.0f);
  _rotation = 0.0f;
  _transform = sf::Transform::Identity;
}

Entity::~Entity()
{

}

void Entity::SetPosition(sf::Vector2f position)
{

  // position
  //sprite.setPosition(position); // absolute position
  //sprite.move(0.0f,0.0f); // offset relative to the current position
  _transform.translate(-_position);
  _position = position;
  _transform.translate(_position);
  /*localPos = position;
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
	}*/
}

void Entity::SetRotation(float rotation)
{
  // rotation
  //sprite.setRotation(rotation); // absolute angle
  //sprite.rotate(rotation / 6); // offset relative to the current angle
  _transform.rotate(-_rotation);
  _rotation = rotation;
  _transform.rotate(_rotation);
}

void Entity::SetScale(sf::Vector2f scaling)
{

  // scale
  //sprite.setScale(scaling); // absolute scale factor
  //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
  _transform.scale(-_scale);
  _scale = scaling;
  _transform.scale(_scale);
  /*localScale = scaling;
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
	}*/
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

void Entity::draw(sf::RenderTarget& target,sf::Transform parentTransform)const
{
  sf::Transform combinedTransform = parentTransform * _transform;

  onDraw(target, combinedTransform);

  for (std::size_t i = 0; i < children.size(); ++i)
    children[i]->draw(target, combinedTransform);
}

void Entity::onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
{
  target.draw(sprite, transform);
}
