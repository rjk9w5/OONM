/*
 * test.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#define DEBUGFULL

#include "exceptions.h"
#include "matrix_dense.h"
#include <iostream>

void
use_cpy_constructor(
    oonm::MatrixDense<double> const &inp);

void
use_move_constructor(
    oonm::MatrixDense<double> inp);

int main(int nargs, char** args)
{
  try
  {
    oonm::MatrixDense<double> mat, matij(4,5);


    for(std::size_t i=0; i<4; ++i)
    {
      for(std::size_t j=0; j<5; ++j)
      {
        matij(i,j) = i*j;
      }
    }

    matij = matij + matij;

    use_move_constructor(matij);
    use_cpy_constructor(matij);
    oonm::Matrix_type<double>* mtij = new oonm::MatrixDense<double>(matij);
    std::cout << "Output\n";
    for(int i=0; i<4; ++i)
    {
      for(int j=0; j<5; ++j)
      {
        std::cout << mtij -> operator()(i,j) << ' ';
      }
      std::cout << '\n';
    }

    delete mtij;
  }
  catch(oonm::Exception &except)
  {
    std::cerr << except.errMsg() << '\n';
  }
  return 0;
}

void
use_cpy_constructor(
    oonm::MatrixDense<double> const &inp)
{
  oonm::MatrixDense<double> tmp(inp);
  return;
}

void
use_move_constructor(
    oonm::MatrixDense<double> inp)
{
  oonm::MatrixDense<double> test(std::move(inp));

  return;
}

