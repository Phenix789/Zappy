#include <iostream>
#include "sfml.hpp"

void	sfml::end()
{
  this->clear();
  this->App.Display();
  std::cout << "Ending graph loop" << std::endl;
}