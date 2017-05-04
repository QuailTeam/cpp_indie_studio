//
// Core.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 12:36:35 2017 arnaud.alies
// Last update Thu May  4 18:13:08 2017 arnaud.alies
//

#include "Core.hpp"
#include "Welcome.hpp"

Core::Core()
{
  receiver = new MyEventReceiver();
  device = irr::createDevice(irr::video::EDT_SOFTWARE,
			     irr::core::dimension2d<irr::u32>(WIDTH, HEIGHT), 16,
			     false, false, false, receiver);
  //!device
  device->setWindowCaption(L"ISIS rp");
  video = device->getVideoDriver();
  scene = device->getSceneManager();
  gui = device->getGUIEnvironment();

  state = new Welcome();
  state->begin(this);
}

Core::~Core()
{
  device->drop();
}

void Core::run()
{
  State *buff;

  while (device->run())
    {
      video->beginScene(true, true, irr::video::SColor(255, 100, 101, 255));
      gui->drawAll();
      scene->drawAll();
      buff = state->update();
      video->endScene();
      if (buff != NULL)
	{
	  delete state;
	  buff->begin(this);
	  state = buff;
	}
    }
}
