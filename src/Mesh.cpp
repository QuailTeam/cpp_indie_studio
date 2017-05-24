//
// Mesh.cpp for u in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 17:24:51 2017 arnaud.alies
// Last update Wed May 24 10:46:36 2017 arnaud.alies
//

#include <stdexcept>
#include "Mesh.hpp"

Mesh::Mesh(Core* core,
	   std::string path,
	   irr::core::vector3df scale,
	   std::string texture_path) :
  _core(core)
{
  mesh = _core->scene->getMesh(path.c_str());
  if (mesh == nullptr)
    throw std::runtime_error("Not found : " + path);
  node = _core->scene->addAnimatedMeshSceneNode(mesh);
  if (node == nullptr)
    throw std::runtime_error("Error loading : " + path);
  if (texture_path != "")
    node->setMaterialTexture(0, _core->video->getTexture(texture_path.c_str()));
  node->setMaterialFlag(irr::video::EMF_LIGHTING,false);
  node->setScale(scale);
}

Mesh::~Mesh()
{
  node->remove();
}
