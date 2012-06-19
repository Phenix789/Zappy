#include "sfml.hpp"

void    sfml::draw_map()
{
  this->drawBackground();
  this->drawTiles();
  this->drawGui();
  this->App.Display();
#ifdef SHOW_FPS
  std::cout << 1.f / App.GetFrameTime() << std::endl;
#endif
}