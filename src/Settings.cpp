//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Mon Jun 12 19:16:54 2017 arnaud.alies
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
  return (nullptr);
}

void	Settings::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100, 0, 0));
  _core->cam->setTarget(irr::core::vector3df(0, 0, 0));
}
