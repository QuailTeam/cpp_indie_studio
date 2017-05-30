//
// Entity.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Fri May 26 10:41:20 2017 arnaud.alies
// Last update Tue May 30 14:42:15 2017 arnaud.alies
//

#ifndef AENTITY_HPP_
#define AENTITY_HPP_

#include "Indie.h"
#include "Map.hpp"
#include "Core.hpp"

class EntityManager;

class AEntity
{
protected:
  Core* _core;
  Map* _map;
  EntityManager* _entity_manager;
public:
  AEntity();
  virtual ~AEntity() {};
  virtual void init(Core* core, Map* map, EntityManager* entity_manager);
  //pure virtual:
  virtual void setPos(irr::core::vector3df target) = 0;
  virtual irr::core::vector3df getPos() const = 0;
  virtual void update() = 0;
};

#endif
