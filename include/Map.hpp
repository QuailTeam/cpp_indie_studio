//
// Map.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 13:13:43 2017 arnaud.alies
// Last update Tue May 23 14:06:25 2017 arnaud.alies
//

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>

enum EMap
  {
    M_EMPTY = 0,
    M_WALL,
    M_PROP
  };

class Map
{
private:
  int _width;
  int _height;
  std::vector<EMap> _map;
public:
  Map(int width, int height);
  virtual ~Map();
  int getWidth() const;
  int getHeight() const;
  EMap get(int x, int y) const;
  void print() const;
};

#endif
