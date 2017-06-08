//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Thu Jun  8 15:07:54 2017 arnaud.alies
//

#include <iostream>
#include "Welcome.hpp"
#include "MainMenu.hpp"

Welcome::Welcome()
{
  _stime = Core::getTime();
  _core = nullptr;
}

Welcome::~Welcome()
{
  delete _bomb;
  _staticText->remove();
}

State *Welcome::update()
{
  int ctime = Core::getTime();
  State *res = nullptr;
  irr::core::vector3df rot;

  rot = _bomb->node->getRotation();
  _bomb->node->setRotation(rot + irr::core::vector3df(1,1,0));
  if (ctime > _stime + DURATION)
    res = new MainMenu();
  _core->cam->setPosition(_core->cam->getPosition() - irr::core::vector3df(0.6,0,0));
  return (res);
}

void Welcome::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100,0,0));
  _core->cam->setTarget(irr::core::vector3df(0,0,0));
  _bomb = new Mesh(_core,
		   "./res/bomb/Bomb.obj",
		   irr::core::vector3df(50,50,50),
		   "./res/bomb/Albedo.png");
  _staticText = _core->gui->addStaticText(L"Hello World!",
					  irr::core::rect<irr::s32>(10,10,260,50),
					  false);
  /*
  Mesh *test = new Mesh(_core,
			"./res/crate/crate1.obj",
			irr::core::vector3df(1,1,1),
			"./res/crate/T_crate1_D.png");
  test->node->setPosition(irr::core::vector3df(0, -200, 200));
  */
}
