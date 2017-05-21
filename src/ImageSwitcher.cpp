//
// ImageSwitcher.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 16:54:24 2017 arnaud.alies
// Last update Sun May 21 13:23:27 2017 arnaud.alies
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
  _image = NULL;
  this->select(false);
}

ImageSwitcher::~ImageSwitcher()
{
  _image->remove();
  _core->video->removeTexture(_texture);
  _core->video->removeTexture(_itexture);
}

void ImageSwitcher::select(bool val)
{
  irr::core::dimension2d<irr::u32> dim = _texture->getSize();
  irr::core::position2d<irr::s32> target;
  irr::core::position2d<irr::s32> real_pos;

  if (_selected == val && _image != NULL)
    return ;
  if (_image != NULL)
    _image->remove();
  real_pos.X = _pos.X - (dim.Width / 2);
  real_pos.Y = _pos.Y - (dim.Width / 2);
  _selected = val;
  _image = _core->gui->addImage((_selected ? _itexture : _texture), real_pos);
}
