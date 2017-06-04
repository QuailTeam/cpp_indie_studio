//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Sun Jun  4 10:58:43 2017 arnaud.alies
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

enum EState
  {
    S_IDLE = 0,
    S_RUN_UP,
    S_RUN_DOWN,
    S_RUN_LEFT,
    S_RUN_RIGHT,
    S_PLANT
  };

class Player : public AEntity
{
protected:
  int _speed;
  EState _state;
  Mesh* _mesh;
  irr::core::vector3df _heading;
  irr::core::vector3df _offset;
public:
  Player();
  virtual ~Player();
  void init(Core*, Map*, EntityManager*);
  void update();
  void validMove(irr::core::vector3df dir);
  irr::core::vector3df getPos() const;
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getRotation() const;
  void setRotation(irr::core::vector3df rot);
  std::string getType() const;
  virtual EState getState();
  void kill();
};

#endif
