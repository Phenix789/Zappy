#include "data_thread.hpp"

data_thread::data_thread() : _state_connection(false)
{
}

data_thread::~data_thread()
{
}

void	data_thread::lock()
{
  this->_mutex.lock();
}

void	data_thread::unlock()
{
  this->_mutex.unlock();
}

bool	data_thread::trylock()
{
  return (this->_mutex.try_lock());
}
