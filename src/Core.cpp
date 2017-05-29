//
// Core.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 12:36:35 2017 arnaud.alies
// Last update Mon May 29 20:34:02 2017 arnaud.alies
//

#include <ctime>
#include "Core.hpp"
#include "Welcome.hpp"

int Core::getTime()
{
  return (static_cast<long int>(std::time(nullptr)));
}

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
  cam = scene->addCameraSceneNode();
  state = new Welcome();
  state->begin(this);
}

Core::~Core()
{
  delete state;
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
      if (buff != nullptr)
	{
	  delete state;
	  buff->begin(this);
	  state = buff;
	}
    }
}
