//
// main.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May  2 15:10:14 2017 arnaud.alies
// Last update Thu May  4 12:48:42 2017 arnaud.alies
//

#include "Indie.h"
#include "Core.hpp"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int	main_tuto()
{
  IrrlichtDevice *device =
    createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
		  false, false, false, 0);
  
  if (!device)
    return 1;
  device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
  IVideoDriver* driver = device->getVideoDriver();
  ISceneManager* smgr = device->getSceneManager();
  IGUIEnvironment* guienv = device->getGUIEnvironment();  

  guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
			rect<s32>(10,10,260,22), true);
  IAnimatedMesh* mesh = smgr->getMesh("irrlicht-1.8.4/media/sydney.md2");
  if (!mesh)
    {
      device->drop();
      return 1;
    }
  IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );
  
  if (node)
    {
      node->setMaterialFlag(EMF_LIGHTING, false);
      node->setMD2Animation(scene::EMAT_STAND);
      node->setMaterialTexture( 0, driver->getTexture("irrlicht-1.8.4/media/sydney.bmp") );
    }
  smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
  float x = 0;
  while (device->run())
    {
      driver->beginScene(true, true, SColor(255,100,101,140));

      node->setPosition(vector3df(0,0,x));
      x += 0.01;
      
      smgr->drawAll();
      guienv->drawAll();
      
      driver->endScene();
    }
  device->drop();
  
  return (0);
}

int	main()
{
  Core	core;

  core.run();
  return (0);
}
