#ifndef __NETWORK_HPP_
#define __NETWORK_HPP_

#include <boost/asio.hpp>
#include "data_thread.hpp"

bool          init_data(data_thread &data, boost::asio::ip::tcp::iostream &sock);
int           network_loop(data_thread &data, boost::asio::ip::tcp::iostream &sock);

#endif /* __NETWORK_HPP_ */
