//
// Mesh.cpp for u in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 17:24:51 2017 arnaud.alies
// Last update Tue May 23 17:37:27 2017 arnaud.alies
//

#include "Mesh.hpp"

Mesh::Mesh(Core* core, std::string path, irr::core::vector3df scale) :
  _core(core)
{
  mesh = _core->scene->getMesh(path.c_str());
  node = _core->scene->addAnimatedMeshSceneNode(mesh);
  node->setMaterialFlag(irr::video::EMF_LIGHTING,false);
  node->setScale(scale);
}

Mesh::~Mesh()
{
  if (node != nullptr)
    node->remove();
}
