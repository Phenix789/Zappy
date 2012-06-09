#include <string>
#include <cstdlib>
#include "utils.hpp"

namespace utils
{
  unsigned short	atos(const std::string &str)
  {
    return ((unsigned short)(std::atoi(str.c_str())));
  }
};
