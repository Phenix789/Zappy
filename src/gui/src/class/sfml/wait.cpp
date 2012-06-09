#include "sfml.hpp"

void	sfml::wait(int tps, bool draw)
{
  while (tps > 0 && is_running())
    {
      this->process_event();
      if (draw)
	this->draw_map();

    }
}
