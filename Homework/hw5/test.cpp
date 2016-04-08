/*
 * test.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#define DEBUGFULL

#include "exceptions.h"
#include "matrix_dense.h"
#include "matrix_tridiag.h"
#include "linearsystem_solvers.h"
#include "pair.h"
#include "coord.h"
#include "istream_utility.h"
#include "cubic.h"
#include <iostream>
#include <fstream>

int main(int nargs, char** args)
{
  try
  {
    oonm::TDMA<double> td_solver;
    std::size_t pts;
    double dummy;
    oonm::Vector<
      oonm::Pair<
        double,
        oonm::Cubic<double>
      >
    > cspline;

    oonm::Vector<oonm::Coordinate<double>> inp;
    oonm::Vector<double> h, b, c, abcd_tmp(4);

    oonm::MatrixTriDiag<double> tdmat;

    if(nargs > 1)
    {
      std::ifstream fin;
      fin.open(args[1]);

      if(!fin.is_open()) throw oonm::FatalError("File not open!");
      std::cout << "Reading Input file:\n";
      fin >> pts;
      std::cout << pts << '\n';
      inp.set_size(pts);
      for(std::size_t i=0; i<pts; ++i)
      {
        oonm::checkIstream(fin);
        fin >> dummy;
        inp[i].x(dummy);
        oonm::checkIstream(fin);
        fin >> dummy;
        inp[i].y(dummy);
      }
      fin.close();
      std::cout << inp << '\n';

      h.set_size(pts-1);

      for(std::size_t i=0; i<pts-1; ++i)
      {
        h[i] = inp[i+1].x() - inp[i].x();
      }

      tdmat.set_size(pts);
      b.set_size(pts);
      tdmat(0,0) = 1;
      b[0] = 0;
      tdmat(pts-1,pts-1) = 1;
      b[pts-1] = 0;

      for(std::size_t i=1; i<pts-1; ++i)
      {
        tdmat(i,i-1) = h[i-1];
        tdmat(i,i) = 2*(h[i-1] + h[i]);
        tdmat(i,i+1) = h[i+1];

        b[i] = (3/h[i])*(inp[i+1].y() - inp[i].y()) -
               (3/h[i-1])*(inp[i].y() - inp[i-1].y());
      }
      std::cout << "=== Start Tri-diagonal Matrix ===\n";
      std::cout << tdmat << '\n';
      std::cout << "=== End Tri-diagonal Matrix ===\n";

      std::cout << "=== Start B Vector ===\n";
      std::cout << b << '\n';
      std::cout << "=== End B Vector ===\n";

      c = td_solver(tdmat,b);

      //std::cout << c << '\n';

      for(std::size_t i=0; i<pts-1; ++i)
      {
        cspline[i].key(inp[i].x());

        abcd_tmp[0] = inp[i].y();
        abcd_tmp[1] = (1/h[i])*(inp[i+1].y() - inp[i].y()) -
                      (h[i]/3)*(2*c[i] + c[i+1]);
        abcd_tmp[2] = c[i];
        abcd_tmp[3] = (c[i+1] - c[i])/(3*h[i]);

        cspline[i].value().coeff(abcd_tmp);
      }


    }
    else
    {

    }

  }
  catch(oonm::Exception &except)
  {
    std::cerr << except.errMsg() << '\n';
  }
  return 0;
}


