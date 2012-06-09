#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <list>
#include <vector>
#include <string>

int	main_gui(const std::string host, const std::string port);

class Network;
namespace game
{
  /* -- Player -- */
  enum	orientation
    {
      NORD,
      EST,
      SUD,
      OUEST
    };

  class player
  {
  public:
    player(int x, int y, int number, orientation ori);
    ~player();

  public:
    orientation		orient;
    int                 number;
    int                 pos_x;
    int                 pos_y;

  public:
    void	set(int x, int y, orientation ori);

  private:
    player();
  };


  /* -- Map -- */
  enum  ress
    {
      NOURRITURE,
      LINEMATE,
      DERAUMATRE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME
    };

  struct tiles
  {
  public:
    tiles();
    void	set(ress type, int nb);

    int ressources[7];
  };

  class map
  {
  public:
    map();
    ~map();

  public:
    void        set_ress(int x, int y, ress type, int nb);
    void        add_player(int x, int y, int num_pl, orientation orient);
    void        rm_player(int num_pl);
    void        setDim(int x, int y);
    const std::vector<tiles>              getTile() const;
    const std::list<game::player>       getPlayer() const;

  private:
    void	set_tile(tiles _tile, ress type, unsigned int nb);

  public:
    //  private:
    int		                size_x;
    int			        size_y;
    std::vector<tiles>          _tiles;
    std::list<game::player>     _players;

  private:
    map(const map &other);
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

  private:
    data(const data &other);
  };

  int	run_gui(game::data &data, Network &sock);
};

#endif /* __GAME_HPP_ */
