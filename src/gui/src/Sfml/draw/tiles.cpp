#include "sfml.hpp"

void    sfml::drawTiles()
{
  int   posx = (data.pos.getX() > 0 ? data.pos.getX() : 0);
  int   posy = (data.pos.getY() > 0 ? data.pos.getY() : 0);
  bool  print_border = false;

  for (int y = posy; y < 1 + posy + (HEIGHT / 64) && y < this->data.map.size_y; y++)
    for (int x = posx; x < 1 + posx + (WIDTH / 64) && x < this->data.map.size_x; x++)
      {
        sprite[SP_GRASS].SetPosition((x - data.pos.getX()) * 64 , (y - data.pos.getY()) * 64);
        App.Draw(sprite[SP_GRASS]);
        drawRessources(x, y);
        drawPlayer(x, y);
        drawEgg(x, y);
        if (x == gui_focus.first && y == gui_focus.second)
          {
            print_border = true;
            sprite[SP_WHITE_SQUARE].SetPosition((x - data.pos.getX()) * 64 , (y - data.pos.getY()) * 64);
          }
      }
  if (print_border)
    App.Draw(sprite[SP_WHITE_SQUARE]);
}