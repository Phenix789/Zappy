#ifndef __NETWORK_HPP_
#define __NETWORK_HPP_

#include <boost/asio.hpp>

class network : public boost::asio::ip::tcp::iostream
{
public:
  network(const std::string &host, const std::string &port);
  ~network();

private:
  network();
};

#endif /* __NETWORK_HPP_ */
