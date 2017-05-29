//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Mon May 29 17:40:52 2017 arnaud.alies
//

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include <vector>
#include "Indie.h"
#include "Core.hpp"
#include "Map.hpp"
#include "State.hpp"
#include "AEntity.hpp"
#include "Bomb.hpp"

class Bomberman : public State
{
private:
  Map* _map;
  Core* _core;
  std::vector<AEntity*> _entities;
protected:
  template<class T>
  void addEntity(irr::core::vector3df pos);
public:
  Bomberman();
  virtual ~Bomberman();
  State* update();
  void begin(Core*);
};

#endif
