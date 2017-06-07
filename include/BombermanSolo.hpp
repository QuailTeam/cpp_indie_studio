//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Wed Jun  7 18:06:14 2017 arnaud.alies
//

#ifndef BOMBERMANSOLO_HPP_
#define BOMBERMANSOLO_HPP_

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
#include "Image.hpp"

#define WAIT_AFTER_DEATH (1200)

class BombermanSolo : public State
{
protected:
  Map* _map;
  Core* _core;
  EntityManager* _entity_manager;
  std::vector<AEntity*> _entities;
  APlayer* _p1;
  bool _running;
  int _time_end;
  int _level;
  Image* _background;
public:
  BombermanSolo();
  BombermanSolo(int level);
  virtual ~BombermanSolo();
  State* update();
  void begin(Core*);
  void spawnBoxes();
  void spawnMonsters();
};

#endif
