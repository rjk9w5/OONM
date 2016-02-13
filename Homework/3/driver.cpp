/*
 * driver.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: ryan
 */

#include <fstream>
#include <cstdlib>
#include "vector.hpp"
using namespace oonm;

int main(int argc, char* argv[])
{
  vector<vector<double>> avec;
  vector<double> bvec;
  std::ifstream fin;

  size_t v_size, step;

  std::cout << 10%1 << 10/1 << '\n';

  fin.open(argv[1]);

  if(fin.is_open())

  fin >> v_size;
  avec.resize(v_size);
  fin >> avec;
  for(int i=0; i<v_size; ++i)
  {
    avec[i].resize(v_size);
    fin >> avec[i];
  }

  std::cin >> step;

  bvec = avec[0].slice(avec[0].begin(), avec[0].end(), step);

  for(auto it: avec)
  {
    std::cout << it;
    std::cout << '\n';
  }

  for(auto it: bvec)
  {
    std::cout << it;
    std::cout << '\n';
  }

  return 0;
}


