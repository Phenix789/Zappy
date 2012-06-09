#include <iostream>
#include "interface/gui.hpp"

int     main(int __attribute__((unused))ac, char __attribute__((unused))**av)
{
  if (ac == 3)
    return (gui::main(av[1], av[2]));
  else
    {
      std::cout << av[0] << " Using 127.0.0.1 4242 by default" << std::endl;
      return (gui::main("127.0.0.1", "4242"));
    }
}
