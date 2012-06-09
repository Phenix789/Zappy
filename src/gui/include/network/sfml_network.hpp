#include <SFML/Network.hpp>
#include "interface/network.hpp"

class sfNetwork : public INetwork
{
public:
  sfNetwork();
  ~sfNetwork();

public:
  bool  send(const std::string &msg);
  bool	send(const std::list<std::string> &list);
  bool  receive(std::string &buffer);

  bool	connect();
  bool  connect(const std::string &host, const std::string &port);
  bool  disconnect();

  bool  setIp(const std::string&host);
  bool  setPort(const std::string &port);

  bool	isWaiting(type which);
  bool  isBlocking(void);
  bool  isValid(void);
  bool  operator!();

private:
  sf::IPAddress		addr;
  unsigned short 	port;
  sf::SocketTCP		sock;

private:
  bool	sendPacket(sf::Packet &packet);

private:
  sfNetwork(const sfNetwork &other);
};
