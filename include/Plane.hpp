//
// Bomb.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Sat Jun 10 16:56:24 2017 arnaud.alies
//

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

class Plane : public AEntity
{
protected:
  Mesh* _mesh;
  bool _first;
  int _target_x;
  int _target_y;
protected:
  irr::core::vector3df getStart(int x, int y);
public:
  irr::core::vector3df vel;
public:
  Plane();
  virtual ~Plane();
  void init(Core*, Map*, EntityManager*);
  void update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType() const;
};

#endif
