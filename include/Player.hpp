//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Wed May 31 10:32:20 2017 arnaud.alies
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

enum EState
  {
    S_IDLE = 0,
    S_WALKING,
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
  void setPos(irr::core::vector3df target);
  void validMove(irr::core::vector3df dir);
  irr::core::vector3df getPos() const;
};

#endif
