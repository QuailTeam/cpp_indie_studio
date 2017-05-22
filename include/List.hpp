//
// List.hpp for uee in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon May 22 11:36:24 2017 arnaud.alies
// Last update Mon May 22 14:25:35 2017 arnaud.alies
//

#ifndef LIST_HPP_
#define LIST_HPP

#include <vector>
#include <string>
#include "Indie.h"
#include "Image.hpp"
#include "Core.hpp"

class List
{
private:
  Core* _core;
  irr::core::position2d<irr::s32> _pos;
  irr::core::position2d<irr::s32> _inc;
  std::vector<Image*> _images;
  std::vector<irr::video::ITexture*> _textures;
  std::vector<irr::video::ITexture*> _itextures;
public:
  List(Core* core,
       irr::core::position2d<irr::s32> pos,
       irr::core::position2d<irr::s32> inc);
  virtual ~List();
  bool addButton(std::string, std::string);
  void render();
};

#endif
