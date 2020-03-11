#include "spacewar.h"

Spacewar::Spacewar()
{
  sf::IpAddress ip = sf::IpAddress::getLocalAddress();
  sf::TcpSocket socket;
  char connectionType;

  std::cout << "(s) for server, (c) for client: ";
  std::cin >> connectionType;

  if(connectionType == 's')
  {
    sf::TcpListener listener;
    listener.listen(2000);
    listener.accept(socket);
  }
  else
  {
    socket.connect(ip, 2000);
  }

  sf::CircleShape tri1(80,3), tri2(80,3);

  tri1.setFillColor(sf::Color::Red);
  tri2.setFillColor(sf::Color::Red);

  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Packets");

  sf::Vector2f prevPosition, p2Position;

  socket.setBlocking(false);

  while(window.isOpen())
  {
    sf::Event Event;
    while(window.pollEvent(Event))
    {
      if (Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }

      prevPosition = tri1.getPosition();

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        tri1.move(0.5f, 0.0f);
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        tri1.move(-0.5f, 0.0f);
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        tri1.move(0.0f, -0.5f);
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        tri1.move(0.0f, 0.5f);

      window.draw(tri1);
      window.draw(tri2);

      window.display();
      window.clear();
    }


  }

}

Spacewar::~Spacewar()
{

}
