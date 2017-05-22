//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Mon May 22 13:23:14 2017 arnaud.alies
//

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "Image.hpp"

class MainMenu : public State
{
private:
  Image *_play;
  Image *_setting;
  Core *_core;
public:
  MainMenu();
  virtual ~MainMenu();
  State *update();
  void begin(Core*);
};

#endif
