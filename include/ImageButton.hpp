//
// ImageButton.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 16:23:11 2017 arnaud.alies
// Last update Sun May 21 15:44:53 2017 arnaud.alies
//

#ifndef IMAGEBUTTON_HPP_
#define IMAGEBUTTON_HPP_

#include <string>
#include "Indie.h"
#include "Core.hpp"

class ImageButton
{
protected:
  Core *_core;
  irr::video::ITexture *_texture;
  irr::video::ITexture *_itexture;
  irr::gui::IGUIImage *_image;
  irr::core::position2d<irr::s32> _pos;
  bool _selected;
public:
  ImageButton(Core *,
	      const irr::io::path &,
	      const irr::io::path &,
	      irr::core::position2d<irr::s32>);
  virtual ~ImageButton();
  void select(bool val);
};

#endif
