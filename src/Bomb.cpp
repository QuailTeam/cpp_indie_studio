//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Fri Jun  2 18:59:46 2017 arnaud.alies
//

#include "Bomb.hpp"
#include "EntityManager.hpp"

Bomb::Bomb()
{
  _time = Core::getTimeMs();
}

void Bomb::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomb/Bomb.obj",
                   irr::core::vector3df(320, 320, 320),
                   "./res/bomb/Albedo.png");
  /*
  irr::scene::IParticleSystemSceneNode* p = _core->scene->addParticleSystemSceneNode();

  p->setPosition(this->getPos());
  p->setScale(irr::core::vector3df(4,4,4));
  p->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  p->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
  p->setMaterialTexture(0, _core->video->getTexture("./res/fire.bmp"));
  p->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
  irr::scene::IParticleEmitter* em = p->createBoxEmitter(irr::core::aabbox3d<irr::f32>(-8,0,-8,8,8,8),
							 irr::core::vector3df(0.0f,0.02f,0.0f),
							 80,120,
							 irr::video::SColor(0,255,255,255),
							 irr::video::SColor(0,255,255,255), 1100,2000);
  em->setMinStartSize(irr::core::dimension2df(20.0f, 10.0f));
  em->setMaxStartSize(irr::core::dimension2df(20.0f, 10.0f));
  
  p->setEmitter(em);
  em->drop();
  irr::scene::IParticleAffector* paf = p->createFadeOutParticleAffector();
  p->addAffector(paf);
  //paf->drop();
  */
}

Bomb::~Bomb()
{
  int x, y;

  this->getPosMap(&x, &y);
  if (_map->get(x, y) == M_OBS)
    _map->set(x, y, M_EMPTY);
  delete _mesh;
}

void Bomb::update()
{
  /* set map collision */
  int x, y;
  this->getPosMap(&x, &y);
  if (_map->get(x, y) == M_EMPTY
      && _entity_manager->getInRange(this->getPos(), UNIT, "player").size() < 1)
    _map->set(x, y, M_OBS);
  
  int ctime = Core::getTimeMs();
  irr::core::vector3df rot = _mesh->node->getRotation();;
  float rot_speed = (ctime - _time) / 50;

  _mesh->node->setRotation(rot + irr::core::vector3df(0, rot_speed, 0));
  if (_time + TIMER < ctime)
    _entity_manager->queueDeleteEntity(this);
}

void Bomb::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target + irr::core::vector3df(0,50,0));
}

irr::core::vector3df Bomb::getPos() const
{
  return (_mesh->node->getPosition());
}

std::string Bomb::getType() const
{
  return ("bomb");
}
