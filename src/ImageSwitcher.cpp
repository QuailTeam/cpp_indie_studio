//
// ImageSwitcher.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 16:54:24 2017 arnaud.alies
// Last update Thu May  4 18:13:35 2017 arnaud.alies
//

#include "ImageSwitcher.hpp"

ImageSwitcher::ImageSwitcher(Core *core,
			     const irr::io::path & src,
			     const irr::io::path & isrc,
			     irr::core::position2d<irr::s32> pos)
{
  _core = core;
  _selected = false;
  _pos = pos;
  _texture = _core->video->getTexture(src);
  _itexture = _core->video->getTexture(isrc);
  _image = _core->gui->addImage(_texture, _pos);
}

ImageSwitcher::~ImageSwitcher()
{
  _image->remove();
  _core->video->removeTexture(_texture);
  _core->video->removeTexture(_itexture);
}

void ImageSwitcher::select(bool val)
{
  if (_selected == val)
    return ;
  _selected = val;
  _image->remove();
  if (_selected)
    _image = _core->gui->addImage(_itexture, _pos);
  else
    _image = _core->gui->addImage(_texture, _pos);
}
