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
      FOOD,
      LINEMATE,
      DERAUMATRE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME
    };

  struct tiles
  {
    tiles();

    int	ressources[7];
  };

  class map
  {
  public:
    map();
    ~map();

  public:
    void        set_ress(unsigned int x, unsigned int y, ress type, unsigned int nb);
    void        add_player(unsigned int x, unsigned int y, int num_pl);
    void        rm_player(int num_pl);
    void        setDim(unsigned int x, unsigned int y);
    const std::vector<tiles>              getTile() const;
    const std::list<game::player>       getPlayer() const;

  public:
    //  private:
    unsigned int                size_x;
    unsigned int                size_y;
    std::vector<tiles>          _tiles;
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
