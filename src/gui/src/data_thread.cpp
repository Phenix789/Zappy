#include "data_thread.hpp"

gui::data_thread::data_thread() : _state_connection(false)
{
}

gui::data_thread::~data_thread()
{
}

void	gui::data_thread::lock()
{
  this->_mutex.lock();
}

void	gui::data_thread::unlock()
{
  this->_mutex.unlock();
}

bool	gui::data_thread::trylock()
{
  return (this->_mutex.trylock());
}
