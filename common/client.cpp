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
  std::cout << "Set Server Ip: ";
  std::cin >> serverString;

  std::string portString;
  std::cout << "Set Server Port: ";
  std::cin >> portString;
  serverPort = std::stoi(portString);

  std::cout << "Set local port: ";
  std::cin >> port;

  socket.bind(port);

  sf::IpAddress sIP(serverString);
  sf::IpAddress serverIp(sIP);
  std::cout << "Got IP: " << serverIp << std::endl;
  socket.send(text.c_str(), text.length() + 1, serverIp, serverPort);
}

void Client::Run()
{
  while(isRunning)
  {
    sf::IpAddress tempIp;
    unsigned short tempPort;
    socket.receive(buffer, sizeof(buffer), received , tempIp, tempPort);
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
}

