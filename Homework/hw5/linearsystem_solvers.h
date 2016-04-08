/* ************************************************************************** *\
 * linearsystem_solvers.h
 *
 *  Created on: Mar 12, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */

/*
 *   Class: sles
 *   Brief: System of Linear Equation Solver (sles) base class
 */

/*
 *    Function: backsup
 *       Brief: Performs backward substitution on input matrix and vector to
 *              find solution
 *       Input: Matrix
 *       Input: Vector
 *         Pre: Matrix must be square and vector must have same size as matrix
 *              has rows and columns.
 *        Post: Performs backward substitution
 *      return: Solution vector
 */

/*
 *   Class: gaussian_elimination
 *   Brief: Gaussian Elimination method Functor class
 */

/*
 *    Function: gaussian_elimination()
 *       Brief: Default constructor
 *         Pre: None
 *        Post: Constructs a ge solver with no pivoting
 */

/*
 *    Function: gaussian_elimination(pivot_type)
 *       Brief: Constructor that specifies pivoting type
 *       Input: pivot_type is an integer
 *         Pre: pivot_type must be either 1 or 2 (any other number isn't bad,
 *              but has the same effect as the default constructor)
 *        Post: Constructs a ge solver with specified pivoting
 *              1: Partial Pivoting;  2: Full Pivoting
 */

/*
 *    Function: operator()(mat, vec)
 *       Brief: Calls gaussian elimination solver
 *       Input: Matrix
 *       Input: Vector
 *         Pre: Matrix must be square, vector must have same size as matrix has
 *              columns and rows.
 *        Post: Solves input linear system
 *      Return: Solution Vector
 */

#ifndef LINEARSYSTEM_SOLVERS_H_
#define LINEARSYSTEM_SOLVERS_H_

#include "vector.h"
#include "matrix_type.h"

#include <cmath>

namespace oonm
{

  template <class Ele_T>
  class sles
  {
    public:
      oonm::Vector<Ele_T>
      backsub(
          oonm::Matrix_type<Ele_T> const &A,
          oonm::Vector<Ele_T> const &b);

  //    oonm::Vector<Ele_T> forwardsub(
  //        oonm::Matrixsq<Ele_T> const &A,
  //        oonm::Vector<Ele_T> const &b);
  };


  template <class Ele_T>
  class gaussian_solver: private sles<Ele_T>
  {
    public:
      gaussian_solver(): partial_pivot(false), full_pivot(false) {}
      gaussian_solver(int const p): partial_pivot(p==1), full_pivot(p==2) {}

      oonm::Vector<Ele_T>
      operator ()(
          oonm::Matrix_type<Ele_T> const &A,
          oonm::Vector<Ele_T> b);

    private:
      using sles<Ele_T>::backsub;
      bool partial_pivot, full_pivot;
  };

  template <class Ele_T>
  class TDMA
  {
    public:
      oonm::Vector<Ele_T>
      operator ()(
          oonm::Matrix_type<Ele_T> const &A,
          oonm::Vector<Ele_T> b);
  };

};

#include "linearsystem_solversI.hpp"

#endif /* LINEARSYSTEM_SOLVERS_H_ */
