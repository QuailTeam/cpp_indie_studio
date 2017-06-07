//
// DuoEndMenu.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun  6 16:14:22 2017 arnaud.alies
// Last update Tue Jun  6 16:16:30 2017 arnaud.alies
//

#include <iostream>
#include "BombermanDuo.hpp"
#include "DuoEndMenu.hpp"

DuoEndMenu::DuoEndMenu() :
  _core(nullptr),
  _img(nullptr),
  _list(nullptr)
{
}

DuoEndMenu::~DuoEndMenu()
{
  delete _list;
  delete _img;
}

State *DuoEndMenu::update()
{
  E_INPUT in;

  in = _core->receiver->lastKey();
  if (in == K_LEFT)
    _list->next();
  if (in == K_RIGHT)
    _list->prev();

  if (_core->receiver->keyState(K_SPACE))
    {
      if (_list->selected() == 0)
        return (new BombermanDuo());
    }
  return (nullptr);
}

void    DuoEndMenu::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100, 0, 0));
  _core->cam->setTarget(irr::core::vector3df(0, 0, 0));

  _list = new List(core,
                   irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 1.2),
                   irr::core::position2d<irr::s32>(60, 0));
  _list->addButton("./res/play.png", "./res/iplay.png");
  _list->addButton("./res/setting.png", "./res/isetting.png");
  _list->update();
  _img = new Image(core,
                   core->video->getTexture((char*)"./res/benladen.png"),
                   irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 4));
}