#ifndef __PARSER_HPP_
#define __PARSER_HPP_

#include <boost/regex.hpp>
#include <map>
#include <list>
#include <string>
#include "game.hpp"

namespace color
{
  extern const char *red;
  extern const char *orange;
  extern const char *white;
};

namespace pfunc
{
  void	fpmsz(game::data &data, const std::string &cmd);
  void	fpbct(game::data &data, const std::string &cmd);
  void	fptna(game::data &data, const std::string &cmd);
  void	fppnw(game::data &data, const std::string &cmd);
  void	fpppo(game::data &data, const std::string &cmd);
  void	fpplv(game::data &data, const std::string &cmd);
  void	fppin(game::data &data, const std::string &cmd);
  void	fppex(game::data &data, const std::string &cmd);
  void	fppbc(game::data &data, const std::string &cmd);
  void	fppic(game::data &data, const std::string &cmd);
  void	fppie(game::data &data, const std::string &cmd);
  void	fppfk(game::data &data, const std::string &cmd);
  void	fppdr(game::data &data, const std::string &cmd);
  void	fppgt(game::data &data, const std::string &cmd);
  void	fppdi(game::data &data, const std::string &cmd);
  void	fpenw(game::data &data, const std::string &cmd);
  void	fpeht(game::data &data, const std::string &cmd);
  void	fpebo(game::data &data, const std::string &cmd);
  void	fpedi(game::data &data, const std::string &cmd);
  void	fpsgt(game::data &data, const std::string &cmd);
  void	fpseg(game::data &data, const std::string &cmd);
  void	fpsmg(game::data &data, const std::string &cmd);
  void	fpsuc(game::data &data, const std::string &cmd);
  void	fpsbp(game::data &data, const std::string &cmd);
};

typedef void (*funcpar)(game::data &data, const std::string &cmd);

class parser
{
public:
  parser();
  ~parser();

public:
  void	parse(std::string &buffer);
  bool	interpret(game::data &data);
  const std::string     getFirstString() const;
  void  delFirstString();
  
private:
  std::list<std::string>		list;
  std::map<std::string, funcpar>	func;
};

#endif /* __PARSER_HPP_ */
