#include "client.h"
#include<iostream>

Client::Client()
{

}

Client::~Client()
{

}

void Client::Start()
{
  std::cout << "(-TCP-) t or u (-UDP-)" << std::endl;
  std::cin >> mode;

  std::cout << "Set Server Ip: ";
  std::cin >> serverString;

  std::string portString;
  std::cout << "Set Server Port: ";
  std::cin >> portString;
  serverPort = std::stoi(portString);

  std::cout << "Set local port: ";
  std::cin >> port;

  std::cout << "Set client name: ";
  std::cin >> clientName;

  sf::IpAddress sIP(serverString);
  sf::IpAddress serverIp(sIP);

  if (mode == 'u')
  {
    Usocket.bind(port);
    Usocket.send(clientName.c_str(), clientName.length() + 1, serverIp, serverPort);
    //Connect(serverString, serverPort, port, clientName);
  }
  if (mode == 't')
  {
    Tsocket.connect(serverIp, serverPort);
    text += std::to_string(port);
    Tsocket.send(text.c_str(), text.length() + 1);
    Tsocket.receive(buffer, sizeof(buffer), received);
    std::cout << buffer << std::endl;
    tcpStatus = 'r';
  }
}

void Client::Run()
{
  isRunning = true;
  std::cout << "Starting loop " << isRunning << std::endl;
  while(isRunning)
  {
    if (mode == 'u')
    {
      sf::IpAddress tempIp;
      unsigned short tempPort;
      Usocket.receive(buffer, sizeof(buffer), received , tempIp, tempPort);
      if (received > 0)
      {
        std::string message = buffer;
        std::cout << "From Ip: " << tempIp << " On port: " << tempPort << std::endl;
        std::cout << "Received: " << message << std::endl;
        if (message == "stop server")
        {
          isRunning = false;
        }
      }
    }
    if (mode == 't')
    {
      /*if (tcpStatus == 's')
      {
        std::getline(std::cin, text);
        Tsocket.send(text.c_str(), text.length() + 1);
        tcpStatus = 'r';
      }
      else if (tcpStatus == 'r')
      {
        Tsocket.receive(buffer, sizeof(buffer), received);
        if (received > 0)
        {
          std::cout << "Received: " << buffer << std::endl;
          tcpStatus = 's';
        }
      }*/
    }
  }
}

void Client::Connect(std::string ip, int externalPort, int localPort, std::string id)
{
  serverString = ip;
  serverPort = externalPort;
  port = localPort;

  Usocket.bind(port);

  sf::IpAddress sIP(serverString);
  sf::IpAddress serverIp(sIP);
  std::cout << "Got IP: " << serverIp << std::endl;
  serverPacket << id << serverString << port;
  SendUDPPacket(serverPacket);
}

void Client::SendUDPPacket(sf::Packet _packet)
{
  Usocket.send(_packet.getData(), _packet.getDataSize(), serverIp, serverPort);
  _packet.clear();
}

void Client::ReceiveUDPPacket(sf::Packet _packet)
{
  Usocket.receive(_packet, serverIp, serverPort);
}

void Client::SendTCPPacket(sf::Packet _packet)
{
  Tsocket.send(_packet);
  _packet.clear();
}

void Client::ReceiveTCPPacket(sf::Packet _packet)
{
  Tsocket.receive(_packet);
}
