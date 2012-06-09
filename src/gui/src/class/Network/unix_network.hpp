#include <iostream>
#include <sstream>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include "network.hpp"

#warning "Le socket arrive a se co alors qu'il ne devrait pas"
Network::Network(const std::string &host, const std::string &port) : sockfd(-1)
{
  struct in_addr	addr;
  struct sockaddr_in	sockaddr;
  int			val;

  std::istringstream(port) >> val;
  if (val > 0 && val < 65536 && inet_aton(host.c_str(), &addr))
    {
      sockaddr.sin_family = AF_INET;
      sockaddr.sin_port = htons(val);
      std::memcpy(&(sockaddr.sin_addr.s_addr), &addr, sizeof(addr));
      this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (this->sockfd != -1)
	connect(this->sockfd, reinterpret_cast<struct sockaddr *>(&sockaddr), sizeof(sockaddr));
    }
}

Network::~Network()
{
  if (this->sockfd != -1)
    this->disconnect();
}

ssize_t	Network::read(std::string &output)
{
  ssize_t	ret;

  if (this->sockfd == -1)
    return (-1);
  output.clear();
  std::memset(this->buffer, 0, 512);
  if ((ret = recv(this->sockfd, this->buffer, 511, 0)) > 0)
    output = this->buffer;
  return (ret);
}

ssize_t	Network::write(const std::string &input)
{
  if (this->sockfd == -1)
    return (-1);
  std::memset(this->buffer, 0, 512);
  std::memcpy(this->buffer, input.c_str(), (input.size() > 511 ? 511 : input.size()));
  return (send(this->sockfd, input.c_str(), input.size(), MSG_NOSIGNAL));
}

bool	Network::is_connect()
{
  if (this->sockfd == -1)
    return (false);
  return (true);
}

bool	Network::read_ready()
{
  fd_set                fd;

  if (this->sockfd == -1)
    return (false);
  FD_ZERO(&fd);
  FD_SET(this->sockfd, &fd);
  std::memset(&timeout, 0, sizeof(timeout));
  this->timeout.tv_usec = 50000;
  select(this->sockfd + 1, &fd, NULL, NULL, &(this->timeout));
  if (FD_ISSET(this->sockfd, &fd))
    {
      if (recv(this->sockfd, this->buffer, 511, MSG_PEEK) <= 0)
	{
	  this->disconnect();
	  return (false);
	}
      return (true);
    }
  return (false);
}

bool	Network::write_ready()
{
  fd_set                fd;

  if (this->sockfd == -1)
    return (false);
  FD_ZERO(&fd);
  FD_SET(this->sockfd, &fd);
  std::memset(&timeout, 0, sizeof(timeout));
  select(this->sockfd + 1, NULL, &fd, NULL, &(this->timeout));
  if (FD_ISSET(this->sockfd, &fd))
    return (true);
  return (false);
}

int	Network::disconnect()
{
  int	ret;

  if (this->sockfd != -1)
    {
      ret = close(this->sockfd);
      this->sockfd = -1;
      return (ret);
    }
  return (0);
}

Network		&operator<<(Network &sock, const std::string &msg)
{
  std::string	copy(msg);
  size_t	size;

  while (copy.size() > 0)
    {
      size = (copy.size() > 511 ? 511 : copy.size());
      if (sock.write(copy.substr(0, size)) == -1)
	{
	  std::cerr << "Network down" << std::endl;
	  return (sock);
	}
      copy.erase(0, size);
    }
  return (sock);
}

Network		&operator>>(Network &sock, std::string &buffer)
{
  std::string	tmp;

  buffer.clear();
  while (sock.read_ready())
    {
      if (sock.read(tmp) == -1)
	{
	  std::cerr << "Network down" << std::endl;
	  return (sock);
	}
      buffer += tmp;
      tmp.clear();
    }
  return (sock);
}

Network		&operator>>(Network &sock, const std::list<std::string> &list)
{
  std::list<std::string>	copy(list);

  while (copy.size() > 0)
    {
      if (sock.write_ready())
        {
          sock << copy.front();
          copy.pop_front();
        }
      else
	std::cerr << "Socket is not ready (down ?)" << std::endl;
    }
  return (sock);
}
