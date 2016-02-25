/*
 * driver.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: ryan
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "norms.h"
#include "vector.h"

int main(int argc, char* argv[])
{
  oonm::Vector<oonm::Vector<double>> avec;
  oonm::Vector<double> bvec;
  std::ifstream fin;
  Norm2<oonm::Vector<double> > L2;

  size_t v_size, step;

  try
  {
  std::cout << 10%1 << 10/1 << '\n';

  fin.open(argv[1]);

  if(fin.is_open())

  fin >> v_size;
  avec.resize(v_size);
  for(size_t i=0; i<v_size; ++i)
  {
    avec[i].resize(v_size);
    fin >> avec[i];
  }

  //std::cin >> step;
  step=5;
  bvec = avec[0].slice(avec[0].begin(), avec[0].end(), step);

  bvec+=bvec;

  bvec = bvec + bvec;
  bvec = bvec/bvec;
  avec[1].sort();
  for(auto it: avec)
  {
    std::cout << it;
    std::cout << '\n';
  }

  std::cout << '\n';

  for(auto it: bvec)
  {
    std::cout << it << ' ';
  }



  std::cout << '\n';

  std::cout << L2(avec[0]) << '\n';

  std::cout << avec[0]*avec[1] << std::endl;
  }
  catch(std::exception& except)
  {
    std::cerr << "There was an error...and it is all your fault!" << std::endl;
  }

  return 0;
}


