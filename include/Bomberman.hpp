//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Mon May 22 17:36:15 2017 arnaud.alies
//

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"

class Bomberman : public State
{
private:
  Core *_core;
public:
  Bomberman();
  virtual ~Bomberman();
  State *update();
  void begin(Core*);
};

#endif
