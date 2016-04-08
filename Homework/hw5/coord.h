/* ************************************************************************** *\
 * coord.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */
#ifndef COORD_H_
#define COORD_H_

#include "pair.h"
#include <ostream>

namespace oonm
{
  template <class T>
  class Coordinate;

  template <class T>
  std::ostream&
  operator << (
      std::ostream& out,
      oonm::Coordinate<T> const &crd);

  template <class T>
  class Coordinate
  {
    private:
      T i_,j_,k_;
    public:
      Coordinate() = default;

      Coordinate(
          T const &x,
          T const &y): i_(x), j_(y) {}

      Coordinate(
          T const &x,
          T const &y,
          T const &z): i_(x), j_(y), k_(z) {}

      bool operator < (Coordinate const &c)
      {
        return (i_ < c.i_?1:(c.i_ < i_?0:(j_ < c.j_?1:0)));
      }

      T x() const {return i_;}
      void x(T const &i) {i_ = i;}

      T i() const {return i_;}
      void i(T const &i) {i_ = i;}

      T y() const {return j_;}
      void y(T const &i) {j_ = i;}

      T j() const {return j_;}
      void j(T const &i) {j_ = i;}

      T z() const {return k_;}
      void z(T const &i) {k_ = i;}

      T k() const {return k_;}
      void k(T const &i) {k_ = i;}
  };

  template <class T>
  std::ostream&
  operator << (
      std::ostream& out,
      oonm::Coordinate<T> const &crd)
  {
    out << crd.x() << ' ' << crd.y();

    return out;
  }

}


#endif /* COORD_H_ */
