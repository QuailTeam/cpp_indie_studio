//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Tue Jun  6 15:30:38 2017 arnaud.alies
//

#ifndef BOMBERMANDUO_HPP_
#define BOMBERMANDUO_HPP_

#include <vector>
#include "Indie.h"
#include "Core.hpp"
#include "Map.hpp"
#include "State.hpp"
#include "EntityManager.hpp"
#include "AEntity.hpp"
#include "Bomb.hpp"
#include "Player1.hpp"
#include "Player2.hpp"

class BombermanDuo : public State
{
protected:
  Map* _map;
  Core* _core;
  EntityManager* _entity_manager;
  std::vector<AEntity*> _entities;
  APlayer* _p1;
  APlayer* _p2;
public:
  BombermanDuo();
  virtual ~BombermanDuo();
  State* update();
  void begin(Core*);
  void spawnBoxes();
};

#endif
