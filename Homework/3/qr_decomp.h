/*
 * qr_decomp.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
 */

/*
 *       class: QR_decomp
 *       brief: Functor class for QR decomposition using the modified
 *              Gram-Schmidt process.
 */

/*
 *    function: operator()
 *       brief: Evaluates the QR decomposition of a given vector set
 *         pre: Vector set must contain a set of more than zero equally
 *              sized vectors of size greater than zero.
 *        post: Returns an array of vector sets. The first element of the array
 *              is the Q vector set and the second element is the R vector set.
 *              TODO: Overload to work with matrix classes
 *      return: Returns an array of vector sets. The first element of the array
 *              is the Q vector set and the second element is the R vector set.
 */

#ifndef QR_DECOMP_H_
#define QR_DECOMP_H_

#include "vector.h"
#include "norms.h"
#include "nl_exceptions.h"
#include <cmath>
#include <iostream>

namespace nl
{
  template <class T>
  class qr_decomp
  {
    public:
      oonm::Vector<oonm::Vector<T>>* operator() (const oonm::Vector<oonm::Vector<T>>& A);
  };
}
#include "qr_decomp.hpp"


#endif /* QR_DECOMP_H_ */
