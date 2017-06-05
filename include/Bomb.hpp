//
// Bomb.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Mon Jun  5 16:46:55 2017 arnaud.alies
//

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

#define BOMB_TIMER (3000)

class Bomb : public AEntity
{
private:
  bool addExplosion(int x, int y);  
protected:
  Mesh* _mesh;
  int _time;
public:
  int range;
public:
  Bomb();
  virtual ~Bomb();
  void init(Core*, Map*, EntityManager*);
  void update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType() const;
  void kill();
};

#endif
