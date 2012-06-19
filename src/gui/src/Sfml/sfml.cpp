#include "sfml.hpp"

sfml::sfml(game::data &edata) : data(edata), run(false)
{
  this->data.pos.setLimit(edata);
  gui_focus.first = -1;
  gui_focus.second = -1;
}

sfml::~sfml()
{
}







