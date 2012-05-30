#ifndef __MAP_HPP_
#define __MAP_HPP_

#include <list>

namespace gui
{
  namespace map
  {
    enum	ress
      {
	LINEMATE = 1,
	DERAUMATRE = 2,
	SIBUR = 4,
	MENDIANE = 8,
	PHIRAS = 16,
	THYSTAME = 32,
	FOOD = 64
      };

    typedef struct	s_case
    {
      ress		obj;
    }			t_case;
  }
}

#endif /* __MAP_HPP_ */
