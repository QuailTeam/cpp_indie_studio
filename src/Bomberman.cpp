//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Wed May 24 18:34:46 2017 arnaud.alies
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
  _map->update();
  return (nullptr);
}

void Bomberman::begin(Core* core)
{
  _core = core;
  _map = new Map(core, 12,12);

  _map->print();
}
