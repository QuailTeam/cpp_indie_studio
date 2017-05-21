//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Sun May 21 15:44:26 2017 arnaud.alies
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
  _play->select(_core->receiver->keyState(K_SPACE));
  return (nullptr);
}

void	MainMenu::begin(Core* core)
{
  irr::core::position2d<irr::s32> play_pos(WIDTH / 2 - 50, HEIGHT / 2);
  irr::core::position2d<irr::s32> setting_pos(WIDTH / 2 + 50, HEIGHT / 2);
  _core = core;

  _play = new ImageButton(core,
			  "./res/play.png",
			  "./res/iplay.png",
			  play_pos);
  _setting = new ImageButton(core,
			     "./res/setting.png",
			     "./res/isetting.png",
			     setting_pos);
}
