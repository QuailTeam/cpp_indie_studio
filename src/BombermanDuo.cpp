//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Tue Jun  6 18:45:21 2017 arnaud.alies
//

#include <ctime>
#include <iostream>
#include "BombermanDuo.hpp"
#include "MainMenu.hpp"
#include "Box.hpp"
#include "random.hpp"

BombermanDuo::BombermanDuo() :
  _core(nullptr),
  _entity_manager(nullptr),
  _time_end(0),
  _running(true)
{
}

BombermanDuo::~BombermanDuo()
{
  delete _entity_manager;
  delete _map;
}

State *BombermanDuo::update()
{
  if (_running)
    {
      if (_core->receiver->keyState(K_ESCAPE))
	return (new MainMenu());
      if (_p1->isAlive() == false
	  || _p2->isAlive() == false)
	{
	  _running = false;
	  _time_end = _core->getTimeMs();
        }
      _entity_manager->update();
    }
  else
    {
      if (_time_end < _core->getTimeMs() - WAIT_AFTER_DEATH)
	{
	  return (new BombermanDuo());
	}
    }
  return (nullptr);
}

void BombermanDuo::spawnBoxes()
{
  std::vector<AEntity*> in_range;

  for (int y = 0; y < _map->getHeight(); y += 1)
    for (int x = 0; x < _map->getWidth(); x += 1)
      {
	if (_map->get(x, y) == M_EMPTY)
	  {
	    in_range = _entity_manager->getInRange(Map::getAbs(x, y), UNIT * 2, "player");
	    if (in_range.size() <= 0
		&& RAND_PERCENT(80))
	      _entity_manager->addEntityMap<Box>(x, y);
	  }
      }
}

void BombermanDuo::begin(Core* core)
{
  _core = core;
  _map = new Map(_core, 11, 11);
  _entity_manager = new	EntityManager(_core, _map);

  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;

  _core->cam->setPosition(irr::core::vector3df(width / 4, width, height / 2));
  _core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  //_entity_manager->addEntity<Bomb>(irr::core::vector3df(3 * UNIT, 0, 3 * UNIT));
  _p1 = _entity_manager->addEntityMap<Player1>(1, 1);
  _p2 = _entity_manager->addEntityMap<Player2>(_map->getWidth() - 2, _map->getHeight() - 2);
  _entity_manager->update();
  //_entity_manager->addEntityMap<Box>(3, 2);
  this->spawnBoxes();
}
