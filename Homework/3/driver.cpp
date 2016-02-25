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
#include "qr_decomp.h"

int main(int argc, char* argv[])
{
  oonm::Vector<oonm::Vector<double>> avec, Q, R, QQ;
  oonm::Vector<double> bvec;
  std::ifstream fin;
  Norm2<oonm::Vector<double> > L2;
  qr_decomp<double> QR;

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

  QR(avec, Q, R);
  QQ = Q;
  //std::cin >> step;
  step=5;
  bvec = avec[0].slice(avec[0].begin(), avec[0].end(), step);

  bvec+=bvec;

  bvec = bvec + bvec;
  bvec = bvec/bvec;
  avec[1].sort();

//  std::cout << avec << std::endl;
//
//  std::cout << Q << std::endl;
//
//  std::cout << R << std::endl;

  std::cout << '\n';
  //std::cout << '\n';

  //std::cout << L2(avec[0]) << '\n';
  size_t it=0, jt=0;
  for(auto q1: Q)
  {
//    for(auto q2: Q)
//    {
      //if(q1!=q2 && q1*q2 > .000001f)
        //std::cout << q1*q2 << std::endl;
        QQ[it][it] = q1*q1;
        jt++;
//    }
    jt=0;
    it++;
  }

  //std::cout << QQ << std::endl;
  oonm::Vector<double> Qkk(Q.get_size());
  it =0;
  for(auto& val: Q)
  {
    Qkk[it++] = val*val;
  }
  //std::cout << '\n' << R[9][9] << std::endl;
  std::cout << Qkk << std::endl;
  //std::cout << R << std::endl;

  std::cout << avec[1] << std::endl;
  std::cout << (Q[1]*avec[1])*Q[1] << std::endl;
  }
  catch(std::exception& except)
  {
    std::cerr << "There was an error...and it is all your fault!" << std::endl;
  }

  return 0;
}


