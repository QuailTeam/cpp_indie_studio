//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Sat Jun  3 16:06:56 2017 arnaud.alies
//

#include "Map.hpp"
#include "Explosion.hpp"
#include "Bomb.hpp"
#include "EntityManager.hpp"

Bomb::Bomb() :
  range(2)
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
}

bool Bomb::addExplosion(int x, int y)
{
  EMap p;

  p = _map->get(x, y);
  if (p == M_WALL)
    return (false);
  _entity_manager->addEntityMap<Explosion>(x, y);
  if (p == M_OBS)
    return (false);
  return (true);
}

Bomb::~Bomb()
{
  int x, y;

  this->getPosMap(&x, &y);
  if (_map->get(x, y) == M_OBS)
    _map->set(x, y, M_EMPTY);
  
  int explosion_x = x;
  int explosion_y = y;
  
  while (explosion_x <= x + range)
    {
      if (this->addExplosion(explosion_x, y) == false)
	break;
      explosion_x += 1;
    }
  while (explosion_y <= y + range)
    {
      if (this->addExplosion(x, explosion_y) == false)
	break;
      explosion_y += 1;
    }
  explosion_x = x;
  explosion_y = y;
  while (explosion_x + range >= x)
    {
      if (this->addExplosion(explosion_x, y) == false)
	break;
      explosion_x -= 1;
    }
  while (explosion_y + range >= y)
    {
      if (this->addExplosion(x, explosion_y) == false)
	break;
      explosion_y -= 1;
    }
  delete _mesh;
}

void Bomb::update()
{
  /* set map collision */
  int x, y;
  this->getPosMap(&x, &y);
  if (_map->get(x, y) == M_EMPTY
      && _entity_manager->getInRange(this->getPos(), UNIT, "player").size() < 1)
    _map->set(x, y, M_OBS);
  
  int ctime = Core::getTimeMs();
  irr::core::vector3df rot = _mesh->node->getRotation();;
  float rot_speed = (ctime - _time) / 50;

  _mesh->node->setRotation(rot + irr::core::vector3df(0, rot_speed, 0));
  if (_time + BOMB_TIMER < ctime)
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

std::string Bomb::getType() const
{
  return ("bomb");
}
