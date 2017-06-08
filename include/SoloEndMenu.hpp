//
// SoloEndMenu.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu Jun  8 15:33:00 2017 arnaud.alies
// Last update Thu Jun  8 16:00:53 2017 arnaud.alies
//

#ifndef SOLOENDMENU_HPP_
#define SOLOENDMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "Image.hpp"
#include "State.hpp"

class SoloEndMenu : public State
{
private:
  int _sel;
protected:
  Core* _core;
public:
  Image* _background;
  irr::gui::IGUIStaticText* _staticText;
public:
  SoloEndMenu(int);
  virtual ~SoloEndMenu();
  void begin(Core*);
  State *update();
};

#endif
