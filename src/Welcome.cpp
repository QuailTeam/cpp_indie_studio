//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Wed May 24 13:33:39 2017 arnaud.alies
//

#include <ctime>
#include <iostream>
#include "Welcome.hpp"
#include "MainMenu.hpp"

Welcome::Welcome()
{
  _stime = static_cast<long int>(std::time(nullptr));
  _core = nullptr;
}

Welcome::~Welcome()
{
  delete _bomb;
  _staticText->remove();
}

State *Welcome::update()
{
  int ctime = static_cast<long int>(std::time(nullptr));
  State *res = nullptr;
  irr::core::vector3df rot;

  rot = _bomb->node->getRotation();
  _bomb->node->setRotation(rot + irr::core::vector3df(1,1,0));
  if (ctime > _stime + DURATION)
    res = new MainMenu();
  return (res);
}

void Welcome::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(0,30,-40));
  _core->cam->setTarget(irr::core::vector3df(5,0,0));
  _bomb = new Mesh(_core,
		   "./res/bomb/Bomb.obj",
		   irr::core::vector3df(50,50,50),
		   "./res/bomb/Albedo.png");
  _staticText = _core->gui->addStaticText(L"Hello World!",
					  irr::core::rect<irr::s32>(10,10,260,22),
					  true);
  /*
  Mesh *test = new Mesh(_core,
			"./res/crate/crate1.obj",
			irr::core::vector3df(1,1,1),
			"./res/crate/T_crate1_D.png");
  test->node->setPosition(irr::core::vector3df(0, -200, 200));
  */
}
