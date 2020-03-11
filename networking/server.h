#ifndef SERVER_H
#define SERVER_H

#include <SFML/Network.hpp>

class Server
{
public:

  Server();
  ~Server();

  void Start();

  void Run();

  sf::TcpSocket socket;
  sf::TcpListener listener;

  char buffer[2000];
  std::size_t received;

  bool isRunning = true;

  std::string text = "Connected to: Server";

  char mode;

};

#endif
