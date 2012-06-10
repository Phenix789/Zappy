#include <string>
#include "game.hpp"

namespace game
{
  data::data() : connection(false)
  { }

  data::~data()
  { }

  bool  data::msgInWaitList()
  {
    if (this->ask.size() > 0)
      return (true);
    return (false);
  }

  void  data::putInWaitList(const std::string &str)
  {
    this->ask.push_back(str);
  }

  void	data::closeConnection()
  {
    this->connection = false;
  }

  void	data::allowConnection()
  {
    this->connection = true;
  }

  bool	data::operator!()
  {
    return (this->connection);
  }
}
