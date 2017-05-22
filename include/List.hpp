//
// List.hpp for uee in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon May 22 11:36:24 2017 arnaud.alies
// Last update Mon May 22 12:03:15 2017 arnaud.alies
//

#ifndef LIST_HPP_
#define LIST_HPP

#include <vector>
#include <string>
#include "Indie.h"
#include "Code.h"

class List
{
private:
  irr::core::position2d<irr::s32> _pos;
  irr::core::position2d<irr::s32> _inc;
  std::vector<Image*> _vec;
public:
  List(irr::core::position2d<irr::s32> pos,
       irr::core::position2d<irr::s32> inc);
  virtual ~List();
  void	addButton(std::string, std::string);
};

#endif
