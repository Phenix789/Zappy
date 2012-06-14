#ifndef __GAME_DATA_HPP_
#define __GAME_DATA_HPP_

#include "map.hpp"

namespace game
{
  class data
  {
  public:
    data();
    ~data();

  public:
    game::map                   map;
    std::list<std::string>      waitList;

  private:
    bool                        connection;

  public:
    void        closeConnection();
    void        allowConnection();
    void        putInWaitList(const std::string &str);
    bool        msgInWaitList();
    bool        operator!();

  private:
    data(const data &other);
  };
};

#endif /* __GAME_DATA_HPP_ */
