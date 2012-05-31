#include "network.hpp"

network::network(const std::string &host, const std::string &port) :
  boost::asio::ip::tcp::iostream(host, port)
{ }

network::~network()
{ }
