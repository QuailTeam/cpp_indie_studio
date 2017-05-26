//
// Map.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 13:46:12 2017 arnaud.alies
// Last update Fri May 26 10:36:05 2017 arnaud.alies
//

#include <iostream>
#include "Map.hpp"

void Map::initMap()
{
  for (int y = 0; y < _height; y += 1)
    for (int x = 0; x < _width; x += 1)
      {
        if (x % 2 == 0 && y % 2 == 0)
          _map.push_back(M_WALL);
	else if (x == 0
		 || x == _width - 1
		 || y == 0
		 || y == _height - 1)
	  _map.push_back(M_WALL);
        else
          _map.push_back(M_EMPTY);
      }
}

Mesh* Map::newWall(int x, int y)
{
  Mesh *buff = new Mesh(_core,
			"./res/crate/crate1.obj",
			irr::core::vector3df(1,1,1),
			"./res/crate/T_crate1_D.png");
  buff->node->setPosition(irr::core::vector3df(x * UNIT, 0, y * UNIT));
}

Mesh* Map::newFloor(int x, int y)
{
  Mesh *buff = new Mesh(_core,
			"./res/floor/Sci-Fi-Floor-1-OBJ.obj",
			irr::core::vector3df(52,52,52),
			"./res/floor/floor.png");
  buff->node->setPosition(irr::core::vector3df(x * UNIT, 0, y * UNIT));
  return (buff);
}

Map::Map(Core* core, int width, int height) :
  _core(core),
  _width(width),
  _height(height)
{
  this->initMap();
  this->update();
}

void Map::clear()
{
  while (_meshes.size() > 0)
    {
      delete _meshes.at(_meshes.size() - 1);
      _meshes.pop_back();
    }
}

void Map::update()
{
  this->clear();
  for (int y = 0; y < _height; y += 1)
    for (int x = 0; x < _width; x += 1)
      {
	if (this->get(x, y) == M_WALL)
	  {
	    _meshes.push_back(this->newWall(x, y));
	 }
	else if (this->get(x, y) == M_EMPTY)
          {
	    _meshes.push_back(this->newFloor(x, y));
          }
      }
  //_loadedMap = _map;
}

Map::~Map()
{
  this->clear();
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
