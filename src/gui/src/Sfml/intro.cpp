#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "sfml.hpp"

void	sfml::intro()
{
#ifndef DEBUG_GRAPH
  sf::Sprite		&var(Sprite[SP_INTRO));

   this->App.Draw(var);
  this->App.Display();
  this->wait(5000);
  this->App.Clear();
#endif
  std::cout << "Beginning graph loop" << std::endl;
}

