//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Mon May 22 13:24:38 2017 arnaud.alies
//

#include <iostream>
#include "MainMenu.hpp"

MainMenu::MainMenu()
{
  _core = nullptr;
}

MainMenu::~MainMenu()
{
  delete _play;
}

State *MainMenu::update()
{
  return (nullptr);
}

void	MainMenu::begin(Core* core)
{
  irr::core::position2d<irr::s32> play_pos(WIDTH / 2 - 50, HEIGHT / 2);
  irr::core::position2d<irr::s32> setting_pos(WIDTH / 2 + 50, HEIGHT / 2);
  _core = core;

  _play = new Image(core,
		    "./res/play.png",
		    play_pos);
  _setting = new Image(core,
		       "./res/setting.png",
		       setting_pos);
}
