//
// Map.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 13:13:43 2017 arnaud.alies
// Last update Thu May 25 15:28:45 2017 arnaud.alies
//

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include "Core.hpp"
#include "Mesh.hpp"

#define UNIT (100)

enum EMap
  {
    M_EMPTY = 0,
    M_WALL
  };

class Map
{
private:
  Core* _core;
  int _width;
  int _height;
  //std::vector<EMap> _loadedMap;
  std::vector<EMap> _map;
  std::vector<Mesh*> _meshes;
  void clear();
protected:
  void initMap();
  Mesh* newWall(int x, int y);
  Mesh* newFloor(int x, int y);
public:
  Map(Core* core, int width, int height);
  virtual ~Map();
  int getWidth() const;
  int getHeight() const;
  EMap get(int x, int y) const;
  void print() const;
  void update();
};

#endif
