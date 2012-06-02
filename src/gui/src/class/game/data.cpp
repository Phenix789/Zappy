#include <string>
#include "game.hpp"

namespace game
{
  data::data() : connection(false)
  { }

  data::~data()
  { }

  bool  data::msg_to_send()
  {
    if (this->ask.size() > 0)
      return (true);
    return (false);
  }

  void  data::send_msg(const std::string &str)
  {
    this->ask.push_back(str);
  }
}
