//
// random.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun Jun  4 16:03:13 2017 arnaud.alies
// Last update Sun Jun  4 16:30:53 2017 arnaud.alies
//

#include <random>
#include "random.hpp"

int randint(int min, int max)
{
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
  return (dist(rng));
}
