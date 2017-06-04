//
// EntityManager.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 09:56:46 2017 arnaud.alies
// Last update Sun Jun  4 12:36:35 2017 arnaud.alies
//

#include "EntityManager.hpp"
#include "AEntity.hpp"

EntityManager::EntityManager(Core* core, Map* map) :
  _core(core),
  _map(map)
{
}

EntityManager::~EntityManager()
{
  this->update();//clears _to_add and _to_delete
  while (_entities.size() > 0)
    {
      delete _entities.at(_entities.size() - 1);
      _entities.pop_back();
    }
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
  _entities.insert(_entities.end(), _to_add.begin(), _to_add.end());
  _to_add.clear();
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

bool EntityManager::exists(AEntity* ent)
{
  for (auto entity : _entities)
    {
      if (entity == ent)
	return (true);
    }
  return (false);
}
