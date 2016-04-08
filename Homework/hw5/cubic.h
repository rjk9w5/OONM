/* ************************************************************************** *\
 * cubic.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */
#ifndef CUBIC_H_
#define CUBIC_H_

#include "vector.h"
#include "exceptions.h"

namespace oonm
{

template <class T>
class Cubic
{
  public:
    void coeff(Vector<T> const &c)
    {
      if(c.get_size() != 4) throw RangeException();
      a_ = c;
    }

    T operator () (T const &x)
    {
      return a_[0] + a_[1]*x + a_[2]*x*x + a_[3]*x*x*x;
    }

  private:
    Vector<T> a_;
};

}

#endif /* CUBIC_H_ */
