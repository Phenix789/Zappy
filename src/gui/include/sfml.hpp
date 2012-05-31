#ifndef __SFML_HPP_
#define __SFML_HPP_

#include "Igui.hpp"

class smfl : public Igui
{
public:
  sfml(const map &map);
  ~sfml();

public:
  void	draw_map();

private:
  const map	map;

private:
  void        draw_background();
  void        draw_gui();
  void        draw_info();
  void        draw_case();
  void        draw_player();

private:
  sfml();
};

#endif /* __SFML_HPP_ */
