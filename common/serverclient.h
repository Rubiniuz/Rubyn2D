#ifndef SERVERCLIENT_H
#define SERVERCLIENT_H

#include <SFML/Network.hpp>
#include <common/serverclient.h>

class ServerClient
{
public:

  ServerClient();
  ~ServerClient();

  sf::IpAddress clientIp;
  unsigned short clientPort;
  std::string clientName;
  int clientId;
  sf::Packet clientPacket;
  char clientData[50];
  char serverData[50];

};

#endif
