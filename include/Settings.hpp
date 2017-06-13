//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Tue Jun 13 10:45:53 2017 arnaud.alies
//

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "Image.hpp"
#include "List.hpp"
#include "Mesh.hpp"

class Settings : public State
{
private:
  Core* _core;
  irr::gui::IGUIScrollBar* _scrollbar;
  irr::gui::IGUIStaticText* _staticText;
public:
  Settings();
  virtual ~Settings();
  State *update();
  void begin(Core*);
  static irr::core::rect<irr::s32> getDim(float margin, int pos, int height = 25);
};

#endif
