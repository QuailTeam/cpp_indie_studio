//
// Core.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 12:29:18 2017 arnaud.alies
// Last update Thu May  4 17:52:55 2017 arnaud.alies
//

#ifndef CORE_HPP_
#define CORE_HPP_

#include "Indie.h"
#include "State.hpp"
#include "MyEventReceiver.hpp"

class Core
{
protected:
  State *state;
public:
  MyEventReceiver *receiver;
  irr::IrrlichtDevice* device;
  irr::video::IVideoDriver* video;
  irr::scene::ISceneManager* scene;
  irr::gui::IGUIEnvironment* gui;
public:
  Core();
  virtual ~Core();
  void run();
};

#endif
