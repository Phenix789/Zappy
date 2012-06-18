#include "game/data.hpp"
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

void	sfml::exit()
{
  this->App.Close();
  this->run = false;
}

bool	sfml::gameloop() const
{
  return (this->run & !(this->data));
}

void	sfml::close()
{
  if (this->App.IsOpened())
    this->App.Close();
  this->run = false;
  throw gui::except("Fermeture par l'utilisateur");
}

void    sfml::PosAddX(float value)
{
  float x = data.pos.getX() + value;
  float lim = data.pos.getLimitX() - (sfml::WIDTH / 64.0) + 1;
  
  data.pos.setX(x > lim ? lim : x);
}

void    sfml::PosAddY(float value)
{
  float y = data.pos.getY() + value;
  float lim = data.pos.getLimitY() - (sfml::HEIGHT / 64.0) + 1;

  data.pos.setY(y > lim ? lim : y);
}