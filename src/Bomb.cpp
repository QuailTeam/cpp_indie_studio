//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Sun May 28 20:49:44 2017 arnaud.alies
//

#include "Bomb.hpp"

Bomb::Bomb()
{
}

void Bomb::init(Core* core, Map *map)
{
  AEntity::init(core, map);
  _mesh = new Mesh(_core,
                   "./res/bomb/Bomb.obj",
                   irr::core::vector3df(320, 320, 320),
                   "./res/bomb/Albedo.png");
}

Bomb::~Bomb()
{
  delete _mesh;
}

void Bomb::update()
{
  irr::core::vector3df rot;
  
  rot = _mesh->node->getRotation();
  _mesh->node->setRotation(rot + irr::core::vector3df(1,0,0));
}

void Bomb::setPos(irr::core::vector3df target)
{
  return (_mesh->node->setPosition(target));
}

irr::core::vector3df Bomb::getPos() const
{
  return (_mesh->node->getPosition());
}
