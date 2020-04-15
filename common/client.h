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


  sf::UdpSocket socket;
  sf::IpAddress serverIp;
  std::string serverString;

  unsigned short port;
  unsigned short serverPort;

  char buffer[2000];
  std::size_t received;

  bool isRunning = true;

  std::string text = "Connected to: Server";

};

#endif
