//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Tue May 30 15:55:42 2017 arnaud.alies
//

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include <vector>
#include "Indie.h"
#include "Core.hpp"
#include "Map.hpp"
#include "State.hpp"
#include "EntityManager.hpp"
#include "AEntity.hpp"
#include "Bomb.hpp"
#include "Player.hpp"

class Bomberman : public State
{
private:
  Map* _map;
  Core* _core;
  EntityManager* _entity_manager;
  std::vector<AEntity*> _entities;
public:
  Bomberman();
  virtual ~Bomberman();
  State* update();
  void begin(Core*);
};

#endif
