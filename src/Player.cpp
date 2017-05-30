//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Tue May 30 21:44:41 2017 arnaud.alies
//

#include "Player.hpp"
#include "EntityManager.hpp"

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
                   "./res/bomb/Bomb.obj",
                   irr::core::vector3df(320, 320, 320),
                   "./res/bomb/Albedo.png");
}

Player::~Player()
{
  delete _mesh;
}

void Player::update()
{
  //E_INPUT in;
  //in = _core->receiver->lastKey();
  if (_core->receiver->keyState(K_UP))
    {
      this->setPos(this->getPos() + irr::core::vector3df(_speed, 0, 0));
    }
  else if (_core->receiver->keyState(K_DOWN))
    {
      this->setPos(this->getPos() + irr::core::vector3df(-_speed, 0, 0));
    }
  else if (_core->receiver->keyState(K_LEFT))
    {
      this->setPos(_map->getValidPos(this->getPos(), irr::core::vector3df(0, 0, _speed)));
    }
  else if (_core->receiver->keyState(K_RIGHT))
    {
      this->setPos(this->getPos() + irr::core::vector3df(0, 0, -_speed));
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
