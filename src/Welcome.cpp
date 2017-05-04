//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Thu May  4 18:15:34 2017 arnaud.alies
//

#include <iostream>
#include "Welcome.hpp"

Welcome::Welcome()
{
  _core = NULL;
}

Welcome::~Welcome()
{
  _staticText->remove();
  delete _play;
}

State *Welcome::update()
{
  _play->select(_core->receiver->keyState(K_SPACE));
  return (NULL);
}

void Welcome::begin(Core* core)
{
  _core = core;

  _play = new ImageSwitcher(core,
			    "./res/play.png",
			    "./res/iplay.png",
			    irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 2));
  
  _staticText = _core->gui->addStaticText(L"Hello World!",
					  irr::core::rect<irr::s32>(10,10,260,22),
					  true);
  
}
