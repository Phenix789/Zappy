#include "sfml.hpp"

void    sfml::exit()
{
  this->App.Close();
  this->run = false;
}