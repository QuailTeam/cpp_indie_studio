//
// Settings.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun 13 14:10:47 2017 arnaud.alies
// Last update Tue Jun 13 14:45:32 2017 arnaud.alies
//

#include <iostream>
#include <fstream>
#include "Settings.hpp"

Settings::Settings()
{
  this->load();
}

Settings::~Settings()
{
  this->save();
}

void Settings::load()
{
  std::ifstream ifstream;

  ifstream.open("settings.bin");
  if (ifstream.is_open() == false)
    {
      _data.map_size = 11;
    }
  else
    {
      ifstream.read((char*)&_data, sizeof(Data));
      ifstream.close();
    }
  std::cout << "Loaded settings" << std::endl;
}

void Settings::save()
{
  std::ofstream ofstream;

  ofstream.open("settings.bin");
  if (ofstream.is_open() == true)
    {
      ofstream.write((char*)&_data, sizeof(Data));
      ofstream.close();
    }
  std::cout << "Saved settings" << std::endl;
}

Data& Settings::get()
{
  return (_data);
}
