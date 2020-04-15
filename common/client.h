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

  void Connect(std::string ip, int externalPort, int localPort);

  void SendUDPPacket(sf::Packet _packet);
  void ReceiveUDPPacket(sf::Packet _packet);

  void SendTCPPacket(sf::Packet _packet);
  void ReceiveTCPPacket(sf::Packet _packet);

  char mode;
  char tcpStatus;

  sf::UdpSocket Usocket;
  sf::TcpSocket Tsocket;
  sf::IpAddress serverIp;
  std::string serverString;

  sf::Packet packet;
  sf::Packet serverPacket;

  unsigned short port;
  unsigned short serverPort;

  char buffer[2000];
  std::size_t received;

  bool isRunning = true;

  std::string text = "Connected to: Client";

};

#endif
