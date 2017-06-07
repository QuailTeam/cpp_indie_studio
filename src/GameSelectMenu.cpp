//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Wed Jun  7 13:13:43 2017 arnaud.alies
//

#include <iostream>

#include "BombermanSolo.hpp"
#include "BombermanDuo.hpp"
#include "GameSelectMenu.hpp"

GameSelectMenu::GameSelectMenu() :
  _core(nullptr),
  _img(nullptr),
  _list(nullptr)
{
}

GameSelectMenu::~GameSelectMenu()
{
  delete _list;
  delete _img;
}

State *GameSelectMenu::update()
{
  E_INPUT in;

  in = _core->receiver->lastKey();
  if (in == K_LEFT)
    _list->next();
  else if (in == K_RIGHT)
    _list->prev();
  else if (in == K_SPACE)
    {
      if (_list->selected() == 0)
	return (new BombermanSolo());
      if (_list->selected() == 1)
	return (new BombermanDuo());
    }
  return (nullptr);
}

void	GameSelectMenu::begin(Core* core)
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
