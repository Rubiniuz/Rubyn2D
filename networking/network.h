#ifndef NETWORK_H
#define NETWORK_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<string>
#include<iostream>
#include<map>

class Network
{
public:

  Network();
  ~Network();
  sf::IpAddress ip = sf::IpAddress::getLocalAddress();
  std::string text = "Connected to: ";
  sf::UdpSocket socket;
  std::map<unsigned short, sf::IpAddress> computerID;
  char connectionType, mode;
  char buffer[2000];
  std::size_t received;

  unsigned short port;

  int maxPlayers;
  std::string playersString;

private:

};

#endif /* NETWORK_H */
