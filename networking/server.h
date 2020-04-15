#ifndef SERVER_H
#define SERVER_H

#include <SFML/Network.hpp>
#include <map>

class Server
{
public:

  Server();
  ~Server();

  void Start();

  void Run();

  sf::UdpSocket Usocket;
  sf::TcpSocket Tsocket;
  sf::TcpListener listener;
  std::map<unsigned short, sf::IpAddress> computerID;

  char buffer[2000];
  std::size_t received;

  unsigned short port;

  char mode;
  char tcpStatus;

  bool isRunning = true;

  std::string text = "Connected to: Server";

  std::string playersString;
  int maxPlayers;
  int connectedPlayers;

};

#endif
