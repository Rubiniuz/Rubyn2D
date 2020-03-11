#ifndef CLIENT_H
#define CLIENT_H

#include <SFML/Network.hpp>

class Client
{
public:

  Client();
  ~Client();

  void Start();

  void Run();

  sf::TcpSocket socket;
  sf::IpAddress serverIp;

  char buffer[2000];
  std::size_t received;

  bool isRunning = true;

  std::string text = "Connected to: Server";

  char mode;

};

#endif
