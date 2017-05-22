//
// ImageButton.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 16:54:24 2017 arnaud.alies
// Last update Mon May 22 16:33:42 2017 arnaud.alies
//

#include "Image.hpp"


Image::Image(Core *core,
	     irr::video::ITexture* texture,
	     irr::core::position2d<irr::s32> pos) :
  _texture(texture),
  _core(core),
  _image(nullptr)
{
  irr::core::dimension2d<irr::u32> dim;
  irr::core::position2d<irr::s32> real_pos;

  if (_texture == nullptr)
    return ;
  dim = _texture->getSize();
  real_pos.X = pos.X - (dim.Width / 2);
  real_pos.Y = pos.Y - (dim.Width / 2);
  _image = _core->gui->addImage(_texture, real_pos);
}

Image::~Image()
{
  if (_image != nullptr)
    _image->remove();
}
