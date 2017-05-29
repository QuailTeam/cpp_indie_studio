//
// AEntity.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 18:20:34 2017 arnaud.alies
// Last update Mon May 29 20:26:32 2017 arnaud.alies
//

#include "AEntity.hpp"

AEntity::AEntity() :
  _core(nullptr),
  _map(nullptr)
{
  
}

void AEntity::init(Core* core, Map *map)
{
  _core = core;
  _map = map;
}
