#include "sfml.hpp"

void	sfml::wait(int tps, bool draw)
{
  sf::Clock	clock;
  
  while (clock.GetElapsedTime() < (tps / 1000 ) && this->is_running())
    {
      this->process_event();
      if (draw)
	this->draw_map();
      else
	this->App.Display();
    }
}
