#ifndef NETWORK_H
#define NETWORK_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<string>
#include<iostream>

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

  sf::TcpListener listener;

  bool done = false;

private:

};

#endif /* NETWORK_H */
