#ifndef __NETWORK_SFML_NETWORK_HPP_
#define __NETWORK_SFML_NETWORK_HPP_

#include <SFML/Network.hpp>
#include <exception>
#include "interface/Inetwork.hpp"

class sfNetwork : public INetwork
{
public:
  sfNetwork();
  ~sfNetwork();

public:
  void  send(const std::string &msg);
  void	send(const std::list<std::string> &list);
  void  receive(std::string &buffer);

  bool	connect();
  bool  disconnect();

  void  setIp(const std::string&host);
  void  setPort(const std::string &port);
  void  setBlocking(bool value);

  bool	isReady(type which);
  bool  isBlocking(void);
  bool  isValid(void);
  bool  operator!();

private:
  sf::IPAddress		        addr;
  unsigned short 	        port;
  sf::SocketTCP		        sock;
  sf::Selector< sf::SocketTCP > selector;

private:
  sfNetwork(const sfNetwork &other);
};

#endif /* __NETWORK_SFML_NETWORK_HPP_ */
