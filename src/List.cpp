//
// List.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon May 22 11:36:15 2017 arnaud.alies
// Last update Mon May 22 14:45:37 2017 arnaud.alies
//

#include "List.hpp"

List::List(Core *core,
	   irr::core::position2d<irr::s32> pos,
	   irr::core::position2d<irr::s32> inc) :
  _core(core),
  _pos(pos),
  _inc(inc)
{
  
}

List::~List()
{
  for (auto texture : _itextures)
    {
      _core->video->removeTexture(texture);
    }
  for (auto texture : _textures)
    {
      _core->video->removeTexture(texture);
    }
}

void List::render()
{
  irr::core::position2d<irr::s32> pos = _pos;
  int x;

  x = 0;
  while (x < _textures.size())
    {
      _images.push_back(new Image(_core, _textures.at(x), pos));
      pos += _inc;
      x += 1;
    }
}


bool List::addButton(std::string image, std::string iimage)
{
  irr::video::ITexture* texture = _core->video->getTexture(image.c_str());
  irr::video::ITexture* itexture = _core->video->getTexture(iimage.c_str());

  if (texture == nullptr || itexture == nullptr)
    return (false);
  _itextures.push_back(itexture);
  _textures.push_back(texture);
  return (true);
}
