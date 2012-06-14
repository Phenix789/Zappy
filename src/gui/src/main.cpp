#include <iostream>
#include "interface/gui.hpp"

int     main(int argc, char **argv)
{
  if (argc == 3)
    return (gui::main(argv[1], argv[2]));
  else
    {
      std::cout << argv[0] << " Using 127.0.0.1 4242 by default" << std::endl;
      return (gui::main("127.0.0.1", "4242"));
    }
}
