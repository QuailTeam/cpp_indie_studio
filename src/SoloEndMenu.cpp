//
// SoloEndMenu.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu Jun  8 15:32:43 2017 arnaud.alies
// Last update Thu Jun  8 17:33:01 2017 arnaud.alies
//

#include <string>
#include "SoloEndMenu.hpp"

SoloEndMenu::SoloEndMenu(int sel) :
  _core(nullptr),
  _sel(sel)
{
  
}

SoloEndMenu::~SoloEndMenu()
{
  delete _background;
  _staticText->remove();
}

State* SoloEndMenu::update()
{
  return (nullptr);
}

void SoloEndMenu::begin(Core* core)
{
  irr::core::stringw text;
  _core = core;
  if (_sel > 0)
    {
      text = irr::core::stringw(std::string("Level: " + std::to_string(_sel + 1)).c_str());
      _background = new Image(core,
			      core->video->getTexture((char*)"./res/next_level.png"),
			      irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT * 0.86));
    }
  else
    {
      _background = new Image(core,
			      core->video->getTexture((char*)"./res/game_over.png"),
			      irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT * 0.86));
    }
  _staticText = _core->gui->addStaticText((const wchar_t*)text.c_str(),
					  irr::core::rect<irr::s32>(10,10,260,50),
					  false);
}
