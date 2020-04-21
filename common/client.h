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

  void UpdateGame();

  char mode;
  char tcpStatus;

  sf::UdpSocket Usocket;
  sf::TcpSocket Tsocket;
  sf::IpAddress serverIp;
  std::string serverString;
  std::string clientName;
  int clientId;

  sf::Packet packet;
  sf::Packet serverPacket;

  char serverData[50];
  char clientData[50];

  std::string convertToString(char* a);

  //std::string serverData;
  //std::string clientData;

  unsigned short port;
  unsigned short serverPort;

  char buffer[2000];
  std::size_t received;

  bool isRunning = true;

  std::string text = "Connected to: Client";

  bool inputs[5];

  sf::Vector2f playerPosition;
  float playerRotation;
  sf::Vector2f enemyPosition;
  float enemyRotation;

  sf::Clock dtClock;
  float dt;

};

#endif
