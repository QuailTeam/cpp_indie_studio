//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Mon May 29 20:54:42 2017 arnaud.alies
//

#include <ctime>
#include <iostream>
#include "Bomberman.hpp"

Bomberman::Bomberman() :
  _core(nullptr)
{
}

Bomberman::~Bomberman()
{
}

State *Bomberman::update()
{
  //_map->update();
  AEntity *ent;
  auto i = std::begin(_entities);
  while (i != std::end(_entities))
    {
      ent = *i;
      if (ent->update())
	{
	  i = _entities.erase(i);
	  delete ent;
	}
      else
	++i;
    }
  return (nullptr);
}

void Bomberman::begin(Core* core)
{
  _core = core;

  _map = new Map(core, 11, 11);

  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;


  _core->cam->setPosition(irr::core::vector3df(width / 2, width, height / 2));
  _core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  this->addEntity<Bomb>(irr::core::vector3df(3 * UNIT, 0, 3 * UNIT));
}

/*
** Entity management
*/

template<class T>
void Bomberman::addEntity(irr::core::vector3df pos)
{
  AEntity *ent;

  ent = new T();
  ent->init(_core, _map);
  ent->setPos(pos);
  _entities.push_back(ent);
}
