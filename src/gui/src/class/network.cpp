#include <sstream>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include "network.hpp"

network::network(const std::string &host, const std::string &port) : sockfd(-1)
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

network::~network()
{
  if (this->sockfd != -1)
    close(this->sockfd);
}

ssize_t	network::read(std::string &output)
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

ssize_t	network::write(const std::string &input)
{
  if (this->sockfd == -1)
    return (-1);
  std::memset(this->buffer, 0, 512);
  std::memcpy(this->buffer, input.c_str(), (input.size() > 511 ? 511 : input.size()));
  return (send(this->sockfd, input.c_str(), input.size(), MSG_NOSIGNAL));
}

bool	network::is_connect()
{
  if (this->sockfd == -1)
    return (false);
  return (true);
}

bool	network::read_ready()
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
    return (true);
  return (false);
}

bool	network::write_ready()
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

int	network::disconnect()
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
