#ifndef __DATA_THREAD_HPP_
#define __DATA_THREAD_HPP_

#include <list>
#include <string>
#include <boost/thread.hpp>
#include "map.hpp"

class	data_thread
{
public:
  data_thread();
  ~data_thread();

public:
  void	lock();
  void	unlock();
  bool	trylock();

public:
  boost::mutex			_mutex;
  game::map			map;
  std::list<std::string>	msg;
  bool				state_connection;
};

#endif /* __DATA_THREAD_HPP_ */
