/*
 * infinity_norm.hpp
 *
 *  Created on: Feb 11, 2016
 *      Author: ryan
 *       Brief: Declaration of infinity_norm template functor class.
 */

/*
 *       class: infinity_norm
 *       brief: Template functor class to perform operations of finding the
 *              infinity norm of a set in vector form.
 */

/*
 *    function: operator()(const std::vector<F>&)
 *       brief: Finds the infinity norm of the input set.
 *        post: Finds the infinity norm of the input set.
 *       param: Input set as a vector.
 *      return: double value of the infinity norm.
 */

#ifndef HOMEWORK_2_INFINITY_NORM_HPP_
#define HOMEWORK_2_INFINITY_NORM_HPP_

#include <vector>

template <class F>
class infinity_norm;

template <class F>
class infinity_norm
{
public:
  double operator ()(const std::vector<F>& v_f);
};

template <class F>
double infinity_norm<F>::operator ()(const std::vector<F>& v_f)
{
  double norm = 0;
  double mag;
  for(auto f: v_f)
  {
    mag = f.magnitude();
    if(mag > norm)
      norm = mag;
  }

  return norm;
}


#endif /* HOMEWORK_2_INFINITY_NORM_HPP_*/
