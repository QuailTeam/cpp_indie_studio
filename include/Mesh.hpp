//
// Mesh.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 17:11:32 2017 arnaud.alies
// Last update Tue May 23 17:38:54 2017 arnaud.alies
//

#ifndef MESH_HPP_
#define MESH_HPP_

#include <string>
#include "Core.hpp"

class Mesh
{
protected:
  Core* _core;
public:
  irr::scene::IAnimatedMesh* mesh;
  irr::scene::ISceneNode* node;
  Mesh(Core* core, std::string path, irr::core::vector3df scale = irr::core::vector3df(1,1,1));
  virtual ~Mesh();
};

#endif
