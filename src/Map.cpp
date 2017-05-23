//
// Map.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 13:46:12 2017 arnaud.alies
// Last update Tue May 23 14:42:38 2017 arnaud.alies
//

#include <iostream>
#include "Map.hpp"

Map::Map(int width, int height) :
  _width(width),
  _height(height)
{
  for (int y = 0; y < _height; y += 1)
    for (int x = 0; x < _width; x += 1)
      {
	if (x % 2 && y % 2)
	  _map.push_back(M_WALL);
	else
	  _map.push_back(M_EMPTY);
      }
}

Map::~Map()
{

}

int Map::getWidth() const
{
  return (_width);
}

int Map::getHeight() const
{
  return (_height);
}

EMap Map::get(int x, int y) const
{
  return (_map.at(x + y * _width));
}

void Map::print() const
{
  for (int y = 0; y < _height; y += 1)
    {
      for (int x = 0; x < _width; x += 1)
      {
	if (this->get(x, y))
	  std::cout << "X";
	else
	  std::cout << " ";
      }
      std::cout << std::endl;
    }
}
