//
// MyEventReceiver.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 14:11:36 2017 arnaud.alies
// Last update Wed May 24 14:14:06 2017 arnaud.alies
//

#include <iostream>
#include <map>
#include "MyEventReceiver.hpp"

MyEventReceiver::MyEventReceiver()
{
  _lastKey = K_UNK;
  for (irr::u32 i = 0; i < K_MAX; i += 1)
    {
      _keyMap[i] = false;
    }
}

MyEventReceiver::~MyEventReceiver()
{
  
}

bool MyEventReceiver::OnEvent(const irr::SEvent& event)
{
  std::map<irr::EKEY_CODE, E_INPUT> map = {
    {irr::EKEY_CODE::KEY_SPACE, K_SPACE},
    {irr::EKEY_CODE::KEY_UP, K_UP},
    {irr::EKEY_CODE::KEY_DOWN, K_DOWN},
    {irr::EKEY_CODE::KEY_LEFT, K_LEFT},
    {irr::EKEY_CODE::KEY_RIGHT, K_RIGHT},
    {irr::EKEY_CODE::KEY_RETURN, K_ENTER}
  };
  E_INPUT input;
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    {
      input = map[event.KeyInput.Key];
      if (event.KeyInput.PressedDown)
	_lastKey = input;
      if (input < K_MAX)
	{
	  _keyMap[input] = event.KeyInput.PressedDown;
	}
      //std::cout << event.KeyInput.Key << std::endl;
    }
  return false;
}
bool MyEventReceiver::keyState(E_INPUT keyCode) const
{
  return _keyMap[keyCode];
}

E_INPUT MyEventReceiver::lastKey()
{
  E_INPUT res;

  res = _lastKey;
  _lastKey = K_UNK;
  return (res);
}
