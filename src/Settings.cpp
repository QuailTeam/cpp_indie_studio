//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Tue Jun 13 09:57:41 2017 arnaud.alies
//

#include "Settings.hpp"
#include "MainMenu.hpp"

Settings::Settings() :
  _core(nullptr)
{
}

Settings::~Settings()
{
}

State *Settings::update()
{
  E_INPUT in;
  in = _core->receiver->lastKey();
  if (in == K_ESCAPE)
    return (new MainMenu());
  printf("%d\n", _scrollbar->getPos());
  return (nullptr);
}

void	Settings::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100, 0, 0));
  _core->cam->setTarget(irr::core::vector3df(0, 0, 0));

  /*
  _core->gui->addEditBox(irr::core::stringw("").c_str(),
			 irr::core::rect<irr::s32>(10, 10, 500, 500));
  */
  _scrollbar = _core->gui->addScrollBar(true, irr::core::rect<irr::s32>(100, 100, 500, 120));
  _scrollbar->setMin(9);
  _scrollbar->setMax(40);
}
