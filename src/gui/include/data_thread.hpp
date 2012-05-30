#ifndef __DATA_THREAD_HPP_
#define __DATA_THREAD_HPP_

#include <list>
#include <string>
#include <boost/thread.hpp>

namespace gui
{
  class	data_thread
  {
  public:
    data_thread();
    ~data_thread();

  public:
    void	lock();
    void	unlock();
    bool	trylock();

  private:
    boost::mutex		_mutex;
    t_map			_map;
    std::list<std::string>	_msg;
    bool			_state_connection;
  };
};

#endif /* __DATA_THREAD_HPP_ */
