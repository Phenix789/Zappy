#include "sfml.hpp"

game::ress      sfml::SprtypeToRess(sfml::sprtype type)
{
  switch (type)
    {
    case sfml::SP_FOOD:
      return (game::FOOD);

    case sfml::SP_LINEMATE:
      return (game::LINEMATE);

    case sfml::SP_DERAUMATRE:
      return (game::DERAUMATRE);

    case sfml::SP_SIBUR:
      return (game::SIBUR);

    case sfml::SP_MENDIANE:
      return (game::MENDIANE);

    case sfml::SP_PHIRAS:
      return (game::PHIRAS);

    case sfml::SP_THYSTAME:
      return (game::THYSTAME);

    default:
      throw gui::except("convertToGame - Bad type");
    }
}

sfml::sprtype     sfml::OrientationToSprite(game::orientation type)
{
  switch (type)
  {
    case game::NORD:
      return (sfml::SP_CHAR_UP);

    case game::SUD:
      return (sfml::SP_CHAR_DOWN);

    case game::EST:
      return (sfml::SP_CHAR_LEFT);

    case game::OUEST:
      return (sfml::SP_CHAR_RIGHT);

    default:
      throw gui::except("convertOrientToSpr");
  }
}