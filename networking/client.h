#ifndef CLIENT_H
#define CLIENT_H

#include <SFML/Network.hpp>
#include <string.h>

class Client
{
public:

  Client();
  ~Client();

  void Start();

  void Run();

  void SendUDPPacket();
  void ReceiveUDPPacket();

  void SendTCPPacket(sf::Packet _packet);
  void ReceiveTCPPacket(sf::Packet _packet);

  void StringToData(std::string message);

  char mode;
  char tcpStatus;

  sf::UdpSocket Usocket;
  sf::TcpSocket Tsocket;
  sf::IpAddress serverIp;
  std::string serverString;
  std::string clientName;

  sf::Packet packet;
  sf::Packet serverPacket;
  char serverData[50];
  char clientData[50];

  unsigned short port;
  unsigned short serverPort;

  char buffer[2000];
  std::size_t received;

  bool isRunning = true;

  std::string text = "Connected to: Client";

};

#endif
