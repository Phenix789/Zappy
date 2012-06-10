#include "sfml.hpp"

void sfml::addPosx(float value)
{
  this->pos[0] += value;
}

void sfml::addPosy(float value)
{
  this->pos[1] += value;
}

float sfml::getPosx(void)
{
  return (this->pos[0]);
}

float sfml::getPosy(void)
{
  return (this->pos[0]);
}