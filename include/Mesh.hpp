//
// Mesh.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 17:11:32 2017 arnaud.alies
// Last update Thu Jun  1 15:11:23 2017 arnaud.alies
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
  irr::scene::IAnimatedMeshSceneNode* node;
  Mesh(Core* core,
       std::string path,
       irr::core::vector3df scale = irr::core::vector3df(1,1,1),
       std::string texture_path= "");
  virtual ~Mesh();
};

#endif
