//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Tue Jun  6 14:01:07 2017 arnaud.alies
//

#ifndef PLAYERBASE_HPP_
#define PLAYERBASE_HPP_

#include <vector>
#include "AEntity.hpp"
#include "Mesh.hpp"
#include "Powerup.hpp"

enum EState
  {
    S_IDLE = 0,
    S_RUN_UP,
    S_RUN_DOWN,
    S_RUN_LEFT,
    S_RUN_RIGHT,
    S_PLANT
  };

class PlayerBase : public AEntity
{
protected:
  bool _alive;
  int _id;
  int _speed;
  int _bomb_range;
  EState _state;
  Mesh* _mesh;
  int _max_bombs;
  
  irr::core::vector3df _heading;
  irr::core::vector3df _offset;
public:
  PlayerBase();
  virtual ~PlayerBase();
  virtual void init(Core*, Map*, EntityManager*);
  void update();
  void validMove(irr::core::vector3df dir);
  irr::core::vector3df getPos() const;
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getRotation() const;
  void setRotation(irr::core::vector3df rot);
  std::string getType() const;
  void kill();
  void applyPowerup(EPowerup power);
  void plantBomb();
  bool isAlive() const;
  int countMyBombs() const;
  /* pure virtual */
  virtual EState getState() = 0;
};

#endif
