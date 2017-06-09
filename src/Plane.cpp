//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Fri Jun  9 14:59:32 2017 arnaud.alies
//

#include "Plane.hpp"
#include "Map.hpp"
#include "EntityManager.hpp"
#include "Bomb.hpp"
#include "random.hpp"

irr::core::vector3df Plane::getRandomStart(int map_width, int map_height)
{
  irr::core::vector3df res;

  res.X = randint(0, map_width);
  res.Y = UNIT;
  res.Z = -map_height;
  return (res);
}

Plane::Plane()
{
  vel = irr::core::vector3df(0, 0, 10);
}

void Plane::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/plane/TAL16OBJ.obj",
                   irr::core::vector3df(50, 50, 50),
                   "./res/plane/TALTS.jpg");
  _mesh->node->setRotation(irr::core::vector3df(-90,0,0));
}

Plane::~Plane()
{
  delete _mesh;
}

void Plane::update()
{
  int x, y;
  this->getPosMap(&x, &y);

  if (this->getPos().Z > _map->getHeight() * UNIT * 2)
    this->setPos(Plane::getRandomStart(_map->getWidth() * UNIT, _map->getHeight() * UNIT));
  this->setPos(this->getPos() + vel);
}

void Plane::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target);
}

irr::core::vector3df Plane::getPos() const
{
  return (_mesh->node->getPosition());
}

std::string Plane::getType() const
{
  return ("plane");
}
