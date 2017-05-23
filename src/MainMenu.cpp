//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Tue May 23 14:12:07 2017 arnaud.alies
//

#include <iostream>
#include "Bomberman.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu() :
  _core(nullptr),
  _swapped(false),
  _img(nullptr),
  _list(nullptr)
{
  
}

MainMenu::~MainMenu()
{
  delete _list;
  delete _img;
}

State *MainMenu::update()
{
  if (_core->receiver->keyState(K_LEFT))
    {
      if (!_swapped)
	_list->next();
      _swapped = true;
    }
  else if (_core->receiver->keyState(K_RIGHT))
    {
      if (!_swapped)
	_list->prev();
      _swapped = true;
    }
  else
    _swapped = false;
  //
  if (_core->receiver->keyState(K_SPACE))
    {
      if (_list->selected() == 0)
	return (new Bomberman());
    }
  return (nullptr);
}

void	MainMenu::begin(Core* core)
{
  _core = core;
  _list = new List(core,
		   irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 1.2),
		   irr::core::position2d<irr::s32>(60, 0));
  _list->addButton("./res/play.png", "./res/iplay.png");
  _list->addButton("./res/setting.png", "./res/isetting.png");
  _list->update();
  _img = new Image(core,
		   core->video->getTexture((char*)"./res/bomberman.png"),
		   irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 4));
}
