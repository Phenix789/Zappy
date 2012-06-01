#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <list>
#include <vector>
#include <string>

class Network;
namespace game
{
  /* -- Player -- */
  enum  state
    {
      DEAD,
      ALIVE,
    };

  class player
  {
  public:
    player(int x, int y, int number);
    ~player();

  public:
    int                 number;
    int                 pos_x;
    int                 pos_y;
    // TODO LATER
    //  int                     level;
    //  std::list<ress> inventory;

  private:
    player();
  };


  /* -- Map -- */
  enum  ress
    {
      LINEMATE = 1,
      DERAUMATRE = 2,
      SIBUR = 4,
      MENDIANE = 8,
      PHIRAS = 16,
      THYSTAME = 32,
      FOOD = 64
    };

  class map
  {
  public:
    map();
    ~map();

  public:
    void        add_ress(unsigned int x, unsigned int y, ress type);
    void        rm_ress(unsigned int x, unsigned int y, ress type);
    void        add_player(unsigned int x, unsigned int y, int num_pl);
    void        rm_player(int num_pl);
    void        setDim(unsigned int x, unsigned int y);
    const std::vector<int>              getTile() const;
    const std::list<game::player>       getPlayer() const;

  private:
    unsigned int                size_x;
    unsigned int                size_y;
    std::vector<int>            _case;
    std::list<game::player>     _players;
  };

  /* -- data -- */
  class data
  {
  public:
    data();
    ~data();

  public:
    game::map                   map;
    std::list<std::string>      ask;
    bool                        connection;

  public:
    void	send_msg(const std::string &str);
    bool	msg_to_send();
  };

  int	run_gui(game::data &data, Network &sock);
};

#endif /* __GAME_HPP_ */
