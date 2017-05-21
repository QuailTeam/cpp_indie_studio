//
// ImageSwitcher.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 16:23:11 2017 arnaud.alies
// Last update Sun May 21 13:18:15 2017 arnaud.alies
//

#ifndef IMAGE_SWITCHER_HPP_
#define IMAGE_SWITCHER_HPP_

#include <string>
#include "Indie.h"
#include "Core.hpp"

class ImageSwitcher
{
protected:
  Core *_core;
  irr::video::ITexture *_texture;
  irr::video::ITexture *_itexture;
  irr::gui::IGUIImage *_image;
  irr::core::position2d<irr::s32> _pos;
  bool _selected;
public:
  ImageSwitcher(Core *,
	      const irr::io::path &,
	      const irr::io::path &,
	      irr::core::position2d<irr::s32>);
  virtual ~ImageSwitcher();
  void select(bool val);
};

#endif
