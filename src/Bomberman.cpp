//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Sun May 28 19:02:04 2017 arnaud.alies
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


  Bomb* bomb = new Bomb();
  bomb->init(_core, _map);
  bomb->setPos(irr::core::vector3df(0,50,0));
}
