#ifndef __NETWORK_HPP_
#define __NETWORK_HPP_

#include <cstddef>
#include <string>
#include <sys/time.h>

class network
{
public:
  network(const std::string &host, const std::string &port);
  ~network();

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
  network();
};

class data_thread;
bool          init_data(data_thread &data, network &sock);
int           network_loop(data_thread &data, network &sock);

#endif /* __NETWORK_HPP_ */
