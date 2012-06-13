#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "sfml.hpp"

void	sfml::intro()
{
#ifndef DEBUG_GRAPH
  sf::Sprite		sprite(this->getImg(INTRO));

  sprite.Resize(WIDTH, HEIGHT);
  this->App.Draw(sprite);
  this->App.Display();
  this->wait(5000);
  this->App.Clear();
#endif
  std::cout << "Beginning graph loop" << std::endl;
}

