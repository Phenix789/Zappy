#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "sfml.hpp"

void	sfml::intro()
{
  sf::Sprite		sprite(this->getImg(INTRO));

  sprite.Resize(800, 800);
  this->App.Draw(sprite);
  this->App.Display();
  this->wait(2000, false);
  std::cout << "Beginning graph loop" << std::endl;
}

void	sfml::end()
{
  this->clear();
  this->App.Display();
  std::cout << "Ending graph loop" << std::endl;
}