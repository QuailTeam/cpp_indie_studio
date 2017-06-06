//
// main.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May  2 15:10:14 2017 arnaud.alies
// Last update Tue Jun  6 17:23:47 2017 arnaud.alies
//

#include <SFML/Audio.hpp>

#include <iostream>
#include "Indie.h"
#include "Core.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int	main()
{
  sf::SoundBuffer buffer;
  if (!buffer.loadFromFile("./res/terrorist_music.ogg"))
    return (1);
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
  
  Core	core;
  
  core.run();
  return (0);
}
