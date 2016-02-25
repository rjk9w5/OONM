/*
 * norms.hpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Norm definitions
 */

template <class OBJ_T, class RETURN_T>
RETURN_T Norm2<OBJ_T, RETURN_T>::operator()(const OBJ_T& set)
{
  RETURN_T innerp = set*set;
  return sqrt(innerp);
}

