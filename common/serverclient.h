#ifndef SERVERCLIENT_H
#define SERVERCLIENT_H

#include <SFML/Network.hpp>
#include <common/serverclient.h>

class ServerClient
{
public:

  ServerClient();
  ~ServerClient();

  void Update();

  sf::IpAddress clientIp;
  unsigned short clientPort;
  std::string clientName;
  int clientId = 1;
  sf::Packet clientPacket;
  char clientData[50];
  char serverData[50];

  bool inputs[5];
  sf::Vector2f position;
  float rotation;

};

#endif
