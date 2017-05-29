//
// Bomb.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Mon May 29 20:53:02 2017 arnaud.alies
//

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

#define TIMER (3)

class Bomb : public AEntity
{
protected:
  Mesh* _mesh;
  int _time;
public:
  Bomb();
  virtual ~Bomb();
  void init(Core*, Map*);
  bool update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
};

#endif
