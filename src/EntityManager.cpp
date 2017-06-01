//
// EntityManager.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 09:56:46 2017 arnaud.alies
// Last update Thu Jun  1 14:52:31 2017 arnaud.alies
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
  for (auto entity : _entities)
    {
      entity->update();
    }
  for (auto entity : _to_delete)
    {
      deleteEntity(entity);
    }
  _to_delete.clear();
}

void EntityManager::deleteEntity(AEntity* entity)
{
  AEntity *ent;
  auto i = std::begin(_entities);
  
  while (i != std::end(_entities))
    {
      ent = *i;
      if (ent == entity)
        {
          i = _entities.erase(i);
          delete ent;
        }
      else
        ++i;
    }
}

void EntityManager::queueDeleteEntity(AEntity* entity)
{
  _to_delete.push_back(entity);
}

std::vector<AEntity*> EntityManager::getInRange(irr::core::vector3df pos,
						float range,
						std::string type)
{
  std::vector<AEntity*> res;

  for (auto entity : _entities)
    {
      if (entity->getPos().getDistanceFrom(pos) <= range
	  && entity->getType() == type)
	res.push_back(entity);
    }
  return (res);
}
