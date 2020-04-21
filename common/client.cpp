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
    sf::Clock dtClock;
    float dt;
    int a = 1;
    while (a == 1)
    {
      dt = dtClock.getElapsedTime().asSeconds();
      if (dt >= 2)
      {
        ReceiveUDPPacket();
        a = 2;
      }
    }

    std::cout << serverData << std::endl;
    clientId = serverData[0];
    playerPosition = sf::Vector2f(serverData[1], serverData[2]);
    playerRotation = serverData[3];
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

  sf::Clock dtClock;
  float dt;

  while(isRunning)
  {
    dt = dtClock.getElapsedTime().asSeconds();
    if (mode == 'u')
    {
      if (dt >= 2)
      {
        printf("\033c");
        std::cout << "\x1B[2J\x1B[H";
        dt = dtClock.restart().asSeconds();

        std::string playerInput = "";
        playerInput += std::to_string(inputs[0]);
        playerInput += ",";
        playerInput += std::to_string(inputs[1]);
        playerInput += ",";
        playerInput += std::to_string(inputs[2]);
        playerInput += ",";
        playerInput += std::to_string(inputs[3]);
        playerInput += ",";
        playerInput += std::to_string(inputs[4]);
        playerInput += ",";

        StringToData(playerInput);

        SendUDPPacket();

        ReceiveUDPPacket();

        UpdateGame();
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

void Client::UpdateGame()
{
  if (serverData[0] == clientId)
  {
    playerPosition.x = serverData[1];
    playerPosition.y = serverData[2];
    playerRotation = serverData[3];
  }
  else
  {
    enemyPosition.x = serverData[1];
    enemyPosition.y = serverData[2];
    enemyRotation = serverData[3];
  }
}

std::string Client::convertToString(char* a)
{
    std::string s = "";
    int size = sizeof(a) / sizeof(char);
    for (int i = 0; i < size; i++)
    {
      s = s + a[i];
    }
    return s;
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
