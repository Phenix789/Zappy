#ifndef __NETWORK_HPP_
#define __NETWORK_HPP_

#include <cstddef>
#include <list>
#include <string>
#include <sys/time.h>
#include "game.hpp"

class Network
{
public:
  Network(const std::string &host, const std::string &port);
  ~Network();

public:
  ssize_t	read(std::string &buffer);
  ssize_t	write(const std::string &buffer);
  bool		is_connect();
  bool		read_ready();
  bool		write_ready();
  int		disconnect();

private:
  struct timeval	timeout;
  char			buffer[512];
  int			sockfd;

private:
  Network();
};

Network		&operator<<(Network &sock, const std::string &msg);
Network		&operator>>(Network &sock, std::string &buffer);

class parser;
namespace network
{
  bool		init_data(game::data &data, Network &sock);
  void		send_list(std::list<std::string> &list, Network &sock);
  bool		iteration(game::data &data, parser &pars, Network &sock);
};

#endif /* __NETWORK_HPP_ */
