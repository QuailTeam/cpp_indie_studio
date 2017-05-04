//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Thu May  4 18:15:02 2017 arnaud.alies
//

#ifndef WELCOME_HPP_
#define WELCOME_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "ImageSwitcher.hpp"

class Welcome : public State
{
private:
  ImageSwitcher *_play;
  Core *_core;
  irr::gui::IGUIStaticText *_staticText;
public:
  Welcome();
  virtual ~Welcome();
  State *update();
  void begin(Core*);
};

#endif
