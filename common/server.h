#ifndef SERVER_H
#define SERVER_H

#include <SFML/Network.hpp>
#include <map>
#include <common/serverclient.h>
#include <string.h>

class Server
{
public:

  Server();
  ~Server();

  void Start();

  void Run();

  void SendUDPPacket(ServerClient* client);
  void ReceiveUDPPacket(ServerClient* client);

  void StringToData(ServerClient* client, std::string message);
  /*
  void SendTCPPacket(sf::Packet _packet);
  void ReceiveTCPPacket(sf::Packet _packet);
  */
  sf::UdpSocket Usocket;
  sf::TcpSocket Tsocket;
  sf::TcpListener listener;
  std::map<unsigned short, sf::IpAddress> computerID;

  std::vector<ServerClient*> clients;
  int currentClientId;

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
