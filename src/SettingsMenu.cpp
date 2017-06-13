//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Tue Jun 13 14:57:23 2017 arnaud.alies
//

#include "SettingsMenu.hpp"
#include "MainMenu.hpp"

SettingsMenu::SettingsMenu() :
  _core(nullptr)
{
}

SettingsMenu::~SettingsMenu()
{
  _scrollbar->setEnabled(false);
  _scrollbar->remove();
  _staticText->remove();
}

State *SettingsMenu::update()
{
  E_INPUT in;
  in = _core->receiver->lastKey();
  if (in == K_ESCAPE)
    return (new MainMenu());
  SETTINGS.map_size = _scrollbar->getPos();
  if (SETTINGS.map_size % 2 == 0)
    SETTINGS.map_size += 1;
  return (nullptr);
}

irr::core::rect<irr::s32> SettingsMenu::getDim(float margin, int pos, int height)
{
  irr::core::rect<irr::s32> res;

  res = irr::core::rect<irr::s32>(WIDTH * margin, pos,
				  WIDTH * (1.0 - margin), pos + height);
  return (res);
}

void	SettingsMenu::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100, 0, 0));
  _core->cam->setTarget(irr::core::vector3df(0, 0, 0));

  /*
  _core->gui->addEditBox(irr::core::stringw("").c_str(),
			 irr::core::rect<irr::s32>(10, 10, 500, 500));
  */
  _staticText = _core->gui->addStaticText(irr::core::stringw("Map size").c_str(),
                                          SettingsMenu::getDim(0.2, 30),
                                          false);
  
  _scrollbar = _core->gui->addScrollBar(true, SettingsMenu::getDim(0.2, 80));
  _scrollbar->setMin(9);
  _scrollbar->setMax(19);
  _scrollbar->setSmallStep(1);
  _scrollbar->setPos(SETTINGS.map_size);
}
