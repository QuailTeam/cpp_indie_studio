//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Tue May 23 14:08:07 2017 arnaud.alies
//

#ifndef WELCOME_HPP_
#define WELCOME_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"

#define DURATION (1)

class Welcome : public State
{
private:
  Core *_core;
  irr::gui::IGUIStaticText *_staticText;
  irr::scene::IAnimatedMesh* _bombermesh;
  irr::scene::IAnimatedMeshSceneNode* _bombernode;
  int _stime;
public:
  Welcome();
  virtual ~Welcome();
  State *update();
  void begin(Core*);
};

#endif
