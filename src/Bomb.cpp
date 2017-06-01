//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Thu Jun  1 10:08:14 2017 arnaud.alies
//

#include "Bomb.hpp"
#include "EntityManager.hpp"

Bomb::Bomb()
{
  _time = Core::getTimeMs();
}

void Bomb::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomb/Bomb.obj",
                   irr::core::vector3df(320, 320, 320),
                   "./res/bomb/Albedo.png");
  _map->set(3, 3, M_OBS);
}


Bomb::~Bomb()
{
  delete _mesh;
}

void Bomb::update()
{
  int ctime = Core::getTimeMs();
  irr::core::vector3df rot;
  float rot_speed = (ctime - _time) / 50;
  
  rot = _mesh->node->getRotation();
  _mesh->node->setRotation(rot + irr::core::vector3df(0, rot_speed, 0));
  if (_time + TIMER < ctime)
    _entity_manager->queueDeleteEntity(this);
}

void Bomb::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target + irr::core::vector3df(0,50,0));
}

irr::core::vector3df Bomb::getPos() const
{
  return (_mesh->node->getPosition());
}
