//
// MyEventReceiver.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 14:09:48 2017 arnaud.alies
// Last update Thu May  4 15:46:06 2017 arnaud.alies
//

#ifndef MY_EVENT_RECEIVER
#define MY_EVENT_RECEIVER

#include "Indie.h"

enum E_INPUT
  {
    K_UP = 0,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_SPACE,
    K_ENTER,
    K_MAX
  };

class MyEventReceiver : public irr::IEventReceiver
{
private:
  bool _keyMap[K_MAX];
public:
  MyEventReceiver();
  virtual ~MyEventReceiver();
  virtual bool OnEvent(const irr::SEvent& event);
  virtual bool keyState(E_INPUT keyCode) const;
};


#endif
