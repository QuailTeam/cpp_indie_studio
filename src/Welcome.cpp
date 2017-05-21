//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Sun May 21 13:49:06 2017 arnaud.alies
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
  _staticText->remove();
}

State *Welcome::update()
{
  int ctime = static_cast<long int>(std::time(nullptr));
  State *res = nullptr;
  
  if (ctime > _stime + DURATION)
    res = new MainMenu();
  return (res);
}

void Welcome::begin(Core* core)
{
  _core = core;
  _staticText = _core->gui->addStaticText(L"Hello World!",
					  irr::core::rect<irr::s32>(10,10,260,22),
					  true);
}
