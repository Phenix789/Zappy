#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "parser.hpp"

parser::parser()
{
  this->func["msz"] = &pfunc::fpmsz;
  this->func["bct"] = &pfunc::fpbct;
  this->func["tna"] = &pfunc::fptna;
  this->func["pnw"] = &pfunc::fppnw;
  this->func["ppo"] = &pfunc::fpppo;
  this->func["plv"] = &pfunc::fpplv;
  this->func["pin"] = &pfunc::fppin;
  this->func["pex"] = &pfunc::fppex;
  this->func["pbc"] = &pfunc::fppbc;
  this->func["pic"] = &pfunc::fppic;
  this->func["pie"] = &pfunc::fppie;
  this->func["pfk"] = &pfunc::fppfk;
  this->func["pdr"] = &pfunc::fppdr;
  this->func["pgt"] = &pfunc::fppgt;
  this->func["pdi"] = &pfunc::fppdi;
  this->func["enw"] = &pfunc::fpenw;
  this->func["eht"] = &pfunc::fpeht;
  this->func["ebo"] = &pfunc::fpebo;
  this->func["edi"] = &pfunc::fpedi;
  this->func["sgt"] = &pfunc::fpsgt;
  this->func["seg"] = &pfunc::fpseg;
  this->func["smg"] = &pfunc::fpsmg;
  this->func["suc"] = &pfunc::fpsuc;
  this->func["sbp"] = &pfunc::fpsbp;
}

parser::~parser()
{ }

void	parser::parse(std::string &str)
{
  std::istringstream    input(str);
  std::string           buffer;

  while (input)
    {
      buffer.clear();
      getline(input, buffer);
      if (buffer.size() > 0)
        {
          this->list.push_back(buffer);
	  std::cout << "Receive : " << buffer << std::endl;
        }
    }
}

bool    parser::interpret(game::data &data)
{
  std::list<std::string>::iterator      it;
  
  if (this->list.size() == 0)
    return (true);
  for (it = list.begin(); it != list.end(); it++)
  {
    this->func[it->substr(0, 3)](data, *it);
  }
  list.clear();
  return (true);
}

const std::string       parser::getFirstString() const
{
  if (this->list.size() == 0)
    return ("");
  return (this->list.front());
}

void parser::delFirstString()
{
  if (this->list.size() > 0)
    this->list.pop_front();       
}