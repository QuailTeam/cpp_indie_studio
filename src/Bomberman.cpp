//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Tue May 30 15:55:32 2017 arnaud.alies
//

#include <ctime>
#include <iostream>
#include "Bomberman.hpp"

Bomberman::Bomberman() :
  _core(nullptr),
  _entity_manager(nullptr)
{
}

Bomberman::~Bomberman()
{
  delete _entity_manager;
}

State *Bomberman::update()
{
  //_map->update();
  _entity_manager->update();
  return (nullptr);
}

void Bomberman::begin(Core* core)
{
  _core = core;
  _map = new Map(_core, 11, 11);
  _entity_manager = new	EntityManager(_core, _map);

  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;


  _core->cam->setPosition(irr::core::vector3df(width / 2, width, height / 2));
  _core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  //_entity_manager->addEntity<Bomb>(irr::core::vector3df(3 * UNIT, 0, 3 * UNIT));
  _entity_manager->addEntityMap<Player>(3, 3);
}
