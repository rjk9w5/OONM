/*
 * norms.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Norm definitions
 */

// TODO: Comments for Norm class

#ifndef NORMS_H_
#define NORMS_H_

#include <cmath>
#include <iostream>
#include "vector.h"

template <class OBJ_T, class RETURN_T=double>
class Norm
{
  public:
    virtual RETURN_T operator () (const OBJ_T& set) = 0;
};

template <class OBJ_T, class RETURN_T=double>
class Norm2
{
  public:
    virtual RETURN_T operator () (const OBJ_T& set);
};

#include "norms.hpp"

#endif /* NORMS_H_ */
