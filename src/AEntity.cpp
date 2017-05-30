//
// AEntity.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 18:20:34 2017 arnaud.alies
// Last update Tue May 30 11:47:59 2017 arnaud.alies
//

#include "AEntity.hpp"

AEntity::AEntity() :
  _core(nullptr),
  _map(nullptr),
  _entity_manager(nullptr)
{
  
}

void AEntity::init(Core* core, Map* map, EntityManager* entity_manager)
{
  _core = core;
  _map = map;
  _entity_manager = entity_manager;
}
