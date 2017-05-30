//
// EntityManager.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon May 29 10:56:34 2017 arnaud.alies
// Last update Tue May 30 11:54:11 2017 arnaud.alies
//

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <vector>
#include "Map.hpp"
#include "Core.hpp"
#include "AEntity.hpp"

class EntityManager
{
protected:
  Map* _map;
  Core* _core;
public:
  std::vector<AEntity*> _entities;
public:
  EntityManager(Core* core, Map* map);
  virtual ~EntityManager();
  void update();
  template<class T>
  void addEntity(irr::core::vector3df pos);
};

template<class T>
void EntityManager::addEntity(irr::core::vector3df pos)
{
  AEntity *ent;

  ent = new T();
  ent->init(_core, _map, this);
  ent->setPos(pos);
  _entities.push_back(ent);
}

#endif
