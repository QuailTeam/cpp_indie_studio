//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Sun Jun  4 18:20:37 2017 arnaud.alies
//

#include "Player.hpp"
#include "EntityManager.hpp"
#include "Bomb.hpp"

Player::Player() :
  _offset(irr::core::vector3df(0, 50, 0)),
  _state(S_IDLE),
  _speed(10),
  _bomb_range(1),
  _alive(true)
  //_max_bombs(1)
{
}

void Player::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomberman/tris.md2",
                   irr::core::vector3df(4, 4, 4),
                   "./res/bomberman/Bomber.PCX");
}

Player::~Player()
{
  delete _mesh;
}

void Player::kill()
{
  _mesh->node->setMD2Animation(irr::scene::EMAT_BOOM);
  _alive = false;
}

void Player::validMove(irr::core::vector3df dir)
{
  this->setPos(_map->getValidPos(this->getPos(), dir));
}

void Player::applyPowerup(EPowerup power)
{
  if (power == P_SPEED)
    _speed += 1;
  if (power == P_RANGE)
    _bomb_range += 1;
}

void Player::plantBomb()
{
  std::vector<AEntity*> bombs = _entity_manager->getInRange(this->getPos(), UNIT, "bomb");
  if (bombs.size() <= 0)
    {
      Bomb* bomb = static_cast<Bomb*>(_entity_manager->addEntityMap<Bomb>(Map::getX(this->getPos()),
									  Map::getY(this->getPos())));
      bomb->range = _bomb_range;
    }
}

EState Player::getState()
{
  EState res = S_IDLE;

  if (_core->receiver->keyState(K_UP))
    res = S_RUN_UP;
  else if (_core->receiver->keyState(K_DOWN))
    res = S_RUN_DOWN;
  else if (_core->receiver->keyState(K_LEFT))
    res = S_RUN_LEFT;
  else if (_core->receiver->keyState(K_RIGHT))
    res = S_RUN_RIGHT;
  else if (_core->receiver->keyState(K_SPACE))
    res = S_PLANT;
  else
    res = S_IDLE;
  return (res);
}

void Player::update()
{
  if (_alive == false)
    return ;
  EState old_state = _state;

  _state = this->getState();
  /* actions */
  if (_state == S_RUN_UP)
    {
      this->validMove(irr::core::vector3df(_speed, 0, 0));
      this->setRotation(irr::core::vector3df(0, 0, 0));
    }
  else if (_state == S_RUN_DOWN)
    {
      this->validMove(irr::core::vector3df(-_speed, 0, 0));
      this->setRotation(irr::core::vector3df(0, 180, 0));
    }
  else if (_state == S_RUN_LEFT)
    {
      this->validMove(irr::core::vector3df(0, 0, _speed));
      this->setRotation(irr::core::vector3df(0, -90, 0));
    }
  else if (_state == S_RUN_RIGHT)
    {
      this->validMove(irr::core::vector3df(0, 0, -_speed));
      this->setRotation(irr::core::vector3df(0, 90, 0));
    }
  else if (_state == S_PLANT)
    {
      this->plantBomb();
    }
  /* animations */
  if (old_state != _state)
    {
      if (_state == S_RUN_UP
	  || _state == S_RUN_DOWN
	  || _state == S_RUN_RIGHT
	  || _state == S_RUN_LEFT)
	_mesh->node->setMD2Animation(irr::scene::EMAT_RUN);
      if (_state == S_PLANT)
	_mesh->node->setMD2Animation(irr::scene::EMAT_PAIN_A);
      if (_state == S_IDLE)
	_mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
    }
  //_mesh->node->setRotation(rot + irr::core::vector3df(0, rot_speed, 0));
  //pf("IN RANGE: %d\n", _entity_manager->getInRange(this->getPos(), UNIT).size());
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

std::string Player::getType() const
{
  return ("player");
}
