#include "sfml.hpp"

void    sfml::draw_map()
{
  this->App.Display();
}

void    sfml::draw_background() { }
void    sfml::draw_gui() { }
void    sfml::draw_info() { }
void    sfml::draw_case() { }
void    sfml::draw_player() { }
void    sfml::clear()
{
  if (this->App.IsOpened())
    this->App.Clear();
}
