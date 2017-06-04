//
// Powerup.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Sun Jun  4 14:23:42 2017 arnaud.alies
//

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

enum EPower
  {
    P_UNK = 0,
    P_SPEED
  };

class Powerup : public AEntity
{
protected:
  Mesh* _mesh;
  EPower _power;
public:
  Powerup();
  virtual ~Powerup();
  void init(Core*, Map*, EntityManager*);
  void update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType() const;
  EPower getPower() const;
};

#endif
