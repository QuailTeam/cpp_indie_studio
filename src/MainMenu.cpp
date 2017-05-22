//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Mon May 22 16:31:30 2017 arnaud.alies
//

#include <iostream>
#include "MainMenu.hpp"

MainMenu::MainMenu()
{
  _core = nullptr;
}

MainMenu::~MainMenu()
{
  //delete _play;
}

State *MainMenu::update()
{
  return (nullptr);
}

void	MainMenu::begin(Core* core)
{
  _core = core;

  List *test = new List(core,
			irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 2),
			irr::core::position2d<irr::s32>(50, 0));
  test->addButton("./res/play.png", "./res/iplay.png");
  test->addButton("./res/setting.png", "./res/isetting.png");

  test->update();
}
