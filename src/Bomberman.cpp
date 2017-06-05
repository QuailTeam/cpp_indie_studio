//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Mon Jun  5 13:03:33 2017 arnaud.alies
//

#include <ctime>
#include <iostream>
#include "Bomberman.hpp"
#include "Box.hpp"

Bomberman::Bomberman() :
  _core(nullptr),
  _entity_manager(nullptr)
{
}

Bomberman::~Bomberman()
{
  delete _entity_manager;
  delete _map;
}

#include "MainMenu.hpp"
State *Bomberman::update()
{
  //_map->update();
  /*
  //testing
  if (_core->receiver->keyState(K_RIGHT))
    return (new MainMenu());
  */
  if (_p1->isAlive() == false || _p2->isAlive() == false)
    return (new Bomberman());
  _entity_manager->update();
  return (nullptr);
}

void Bomberman::spawnBoxes()
{
  std::vector<AEntity*> in_range;

  for (int y = 0; y < _map->getHeight(); y += 1)
    for (int x = 0; x < _map->getWidth(); x += 1)
      {
	if (_map->get(x, y) == M_EMPTY)
	  {
	    in_range = _entity_manager->getInRange(Map::getAbs(x, y), UNIT * 2, "player");
	    if (in_range.size() <= 0)
	      _entity_manager->addEntityMap<Box>(x, y);
	  }
      }
}

void Bomberman::begin(Core* core)
{
  _core = core;
  _map = new Map(_core, 11, 11);
  _entity_manager = new	EntityManager(_core, _map);

  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;

  _core->cam->setPosition(irr::core::vector3df(width / 4, width, height / 2));
  _core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  //_entity_manager->addEntity<Bomb>(irr::core::vector3df(3 * UNIT, 0, 3 * UNIT));
  _p1 = _entity_manager->addEntityMap<Player>(1, 1);
  _p2 = _entity_manager->addEntityMap<Player2>(_map->getWidth() - 2, _map->getHeight() - 2);
  _entity_manager->update();
  //_entity_manager->addEntityMap<Box>(3, 2);
  this->spawnBoxes();
}
