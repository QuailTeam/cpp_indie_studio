//
// EntityManager.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 09:56:46 2017 arnaud.alies
// Last update Tue May 30 10:24:32 2017 arnaud.alies
//

#include "EntityManager.hpp"

EntityManager::EntityManager(Core* core, Map* map) :
  _core(core),
  _map(map)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::update()
{
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
}
