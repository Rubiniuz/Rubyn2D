#include "server.h"
#include<iostream>

Server::Server()
{

}

Server::~Server()
{

}

void Server::Start()
{
  std::cout << "(-TCP-) t or u (-UDP-)" << std::endl;
  std::cin >> mode;

  std::cout << "Set server port: ";
  std::cin >> port;

  std::cout << "Set max number of players: ";
  std::cin >> playersString;
  maxPlayers = std::stoi(playersString);

  connectedPlayers = 0;
  currentClientId = 0;

  if (mode == 'u')
  {
    Usocket.bind(port);
    do {
      sf::IpAddress rIp;
      unsigned short port;
      Usocket.receive(buffer, sizeof(buffer), received, rIp, port);
      if (received > 0)
      {
        computerID[port] = rIp;
        std::cout << "Received connection from Ip: " << rIp << " Running Port: " << port << " With clientName: " << buffer << std::endl;
        ServerClient* client = new ServerClient();
        client->clientIp = rIp;
        client->clientPort = port;
        client->clientName = buffer;
        client->clientId = currentClientId;
        clients.push_back(client);
        currentClientId++;
        connectedPlayers++;
      }
    } while(connectedPlayers != maxPlayers);
  }
  if (mode == 't')
  {
    listener.listen(port);
    listener.accept(Tsocket);
    Tsocket.send(text.c_str(), text.length() + 1);
    Tsocket.receive(buffer, sizeof(buffer), received);
    std::cout << buffer << std::endl;
    tcpStatus = 's';
  }
}

void Server::Run()
{
  isRunning = true;
  std::cout << "Starting loop " << isRunning << std::endl;
  while(isRunning)
  {
    if (mode == 'u')
    {
      std::getline(std::cin, text);
      if (text == "stop server")
      {
        isRunning = false;
      }
      for(auto &c : clients)
      {
        std::cout << "for client id: " << c->clientId << " add client name to client packet." << std::endl;
        c->clientPacket << c->clientName;
        std::cout << "finished packing data sending to client!" << std::endl;
        SendUDPPacket(c);
        std::cout << "send data to client!" << std::endl;
      }

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

void Server::SendUDPPacket(ServerClient* client)
{
  Usocket.send(client->clientPacket.getData(), client->clientPacket.getDataSize(), client->clientIp, client->clientPort);
  client->clientPacket.clear();
}

void Server::ReceiveUDPPacket(ServerClient* client)
{
  Usocket.receive(client->clientPacket, client->clientIp, client->clientPort);
}
/*
void Server::SendTCPPacket(sf::Packet _packet)
{
  Tsocket.send(_packet);
  _packet.clear();
}

void Server::ReceiveTCPPacket(sf::Packet _packet)
{
  Tsocket.receive(_packet);
}
*/
