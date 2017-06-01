//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Thu Jun  1 13:59:19 2017 arnaud.alies
//

#include "Player.hpp"
#include "EntityManager.hpp"
#include "Bomb.hpp"

Player::Player() :
  _offset(irr::core::vector3df(0, 50, 0)),
  _state(S_IDLE),
  _speed(10)
{
}

void Player::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomberman/tris.md2",
                   irr::core::vector3df(5, 5, 5),
                   "./res/bomberman/Bomber.PCX");
}

Player::~Player()
{
  delete _mesh;
}

void Player::validMove(irr::core::vector3df dir)
{
  this->setPos(_map->getValidPos(this->getPos(), dir));
}

void Player::update()
{
  E_INPUT in;

  in = _core->receiver->lastKey();
  if (in == K_SPACE)
    {
      _entity_manager->addEntityMap<Bomb>(Map::getX(this->getPos()), Map::getY(this->getPos()));
    }
  if (_core->receiver->keyState(K_UP))
    {
      this->validMove(irr::core::vector3df(_speed, 0, 0));
      this->setRotation(irr::core::vector3df(0, 0, 0));
    }
  else if (_core->receiver->keyState(K_DOWN))
    {
      this->validMove(irr::core::vector3df(-_speed, 0, 0));
      this->setRotation(irr::core::vector3df(0, 180, 0));
    }
  else if (_core->receiver->keyState(K_LEFT))
    {
      this->validMove(irr::core::vector3df(0, 0, _speed));
      this->setRotation(irr::core::vector3df(0, -90, 0));
    }
  else if (_core->receiver->keyState(K_RIGHT))
    {
      this->validMove(irr::core::vector3df(0, 0, -_speed));
      this->setRotation(irr::core::vector3df(0, 90, 0));
    }
  //_mesh->node->setRotation(rot + irr::core::vector3df(0, rot_speed, 0));
}

void Player::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target + _offset);
}

irr::core::vector3df Player::getPos() const
{
  return (_mesh->node->getPosition() - _offset);
}

irr::core::vector3df Player::getRotation() const
{
  return (_mesh->node->getRotation());
}

void Player::setRotation(irr::core::vector3df rot)
{
  _mesh->node->setRotation(rot);
}
