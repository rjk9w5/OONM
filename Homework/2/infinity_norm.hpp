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

template <class Object_t>
class infinity_norm;

template <class Object_t>
class infinity_norm
{
public:
  double operator ()(const std::vector<Object_t>& v_f);
};

template <class Object_t>
double infinity_norm<Object_t>::operator ()
    (const std::vector<Object_t>& object_vector)
{
  double norm = 0;
  double mag;
  for(auto obj: object_vector)
  {
    mag = obj.magnitude();
    if(mag > norm)
      norm = mag;
  }

  return norm;
}


#endif /* HOMEWORK_2_INFINITY_NORM_HPP_*/
