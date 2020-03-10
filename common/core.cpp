#include <common/core.h>

Core::Core()
{

}

Core::~Core()
{

}

void Core::CreateWindow()
{
  currentMode = sf::VideoMode::getDesktopMode();
  std::cout << "Got current mode" << '\n';

  window.create(currentMode, "Tutorial", sf::Style::Fullscreen);
  std::cout << "Window created" << '\n';

  isRunning = true;
}

void Core::Start()
{
  if(scenes[0] != nullptr)
  {
    currentScene = scenes[0];
  }
}

void Core::Run()
{
  CheckWindowState();
  window.clear(sf::Color::White);
  Draw(currentScene);
  window.display();
}

void Core::Draw(Entity* entity)
{
  entity->Draw(window, sf::RenderStates::Default);
  // Render all Children (recursively)
	std::vector<Entity*> children = entity->Children();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->Draw(*child);
	}
}

void Core::CheckWindowState()
{
  if (window.isOpen())
  {
    if (window.pollEvent(eventHandler))
    {
      switch(eventHandler.type)
      {
        case sf::Event::Closed:
          isRunning = false;
          window.close();
          break;

        case sf::Event::KeyPressed:
          if (eventHandler.key.code == sf::Keyboard::Escape)
          {
            isRunning = false;
            window.close();
          }
          if (eventHandler.key.code == sf::Keyboard::F1)
          {
            window.close();
            currentMode = sf::VideoMode::getDesktopMode();
            window.create(currentMode, "Tutorial", sf::Style::Fullscreen);
            std::cout << "Fullscreen Mode" << '\n';
          }
          if (eventHandler.key.code == sf::Keyboard::F2)
          {
            window.close();
            currentMode = sf::VideoMode::getDesktopMode();
            window.create(currentMode, "Tutorial");
            std::cout << "Fullscreen Border Mode" << '\n';
          }
          if (eventHandler.key.code == sf::Keyboard::F3)
          {
            window.close();
            currentMode = sf::VideoMode(970 , 540);
            window.create(currentMode, "Tutorial");
            std::cout << "Window Mode" << '\n';
          }
          break;
        default:
          isRunning = true;
          break;
      }
    }
  }
}

void Core::Clear()
{
  window.clear(sf::Color::Black);
}

void Core::Render(sf::Drawable* toRender)
{
  window.draw(*toRender);
  window.display();
}
