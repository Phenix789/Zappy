#include "sfml.hpp"

void	sfml::wait(int tps)
{
  sf::Clock	clock;
  float	time = tps / 1000;
  
  while ((clock.GetElapsedTime() < time) && this->gameloop())
    {
      this->process_event();
      this->App.Display();
    }
}
