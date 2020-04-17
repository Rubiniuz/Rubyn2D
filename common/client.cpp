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
      /*sf::IpAddress tempIp;
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
      }*/
      ReceiveUDPPacket(packet);
      std::string servermessage;
      packet >> servermessage;
      std::cout << "got this from server: " << servermessage << std::endl;
        ReceiveUDPPacket();
        StringToData("Dont Stop");
        SendUDPPacket();
    }
    if (mode == 't')
    {
      if (tcpStatus == 's')
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
      }
    }
  }
}

void Client::StringToData(std::string message)
{
  strncpy(clientData, message.c_str(), sizeof(clientData));
  clientData[sizeof(clientData)-1] = '\0';
}

void Client::SendUDPPacket()
{
  if(Usocket.send(clientData, sizeof(clientData), serverIp, serverPort) == sf::Socket::Done)
  {
    std::cout << "succesfully send all data." << std::endl;
  }
}

void Client::ReceiveUDPPacket()
{
  std::size_t received;

  if(Usocket.receive(serverData, sizeof(serverData), received , serverIp, serverPort) == sf::Socket::Done)
  {
    if (received > 0)
    {
      //serverData = buffer;
      std::cout << "Received: " << serverData << std::endl;
    }
  }
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
