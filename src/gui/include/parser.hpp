#ifndef __PARSER_HPP_
#define __PARSER_HPP_

#include <list>
#include <string>
#include "data_thread.hpp"

namespace parser
{
  bool	parse_command(std::string &str, std::list<std::string> &list);
  bool	interpret_command(std::list<std::string> &list, data_thread &data);
};

#endif /* __PARSER_HPP_ */
