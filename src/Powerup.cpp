//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Sun Jun  4 15:29:07 2017 arnaud.alies
//

//#include <random>
#include "Map.hpp"
#include "Powerup.hpp"
#include "EntityManager.hpp"
#include "Player.hpp"

Powerup::Powerup()
{
  /*
  std::random_device rd;
  std::mt19937 rng(std::rd());
  std::uniform_int_distribution<int> std::uni(1, 10);
 
  auto random_integer = std::uni(rng);
  */
  
  _power = P_SPEED;
}

void Powerup::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomb/Bomb.obj",
                   irr::core::vector3df(220, 220, 220),
                   "./res/bomb/Albedo.png");
}

Powerup::~Powerup()
{
  delete _mesh;
}

void Powerup::update()
{
  irr::core::vector3df rot = _mesh->node->getRotation();;

  _mesh->node->setRotation(rot + irr::core::vector3df(0, 10, 0));

  std::vector<AEntity*> players = _entity_manager->getInRange(this->getPos(), UNIT / 2, "player");
  for (auto ent : players)
    {
      Player* player = static_cast<Player*>(ent);
      player->applyPowerup(_power);
    }
  if (players.size() > 0)
    this->kill();
}

void Powerup::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target + irr::core::vector3df(0,50,0));
}

irr::core::vector3df Powerup::getPos() const
{
  return (_mesh->node->getPosition() - irr::core::vector3df(0,50,0));
}

std::string Powerup::getType() const
{
  return ("powerup");
}
