/*
 * qr_decomp.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
 */
#ifndef QR_DECOMP_H_
#define QR_DECOMP_H_

#include "vector.h"
#include <cmath>
#include <iostream>

template <class T>
class qr_decomp
{
  public:
    void operator() (const oonm::Vector<oonm::Vector<T>>& A,
                     oonm::Vector<oonm::Vector<T>>& Q,
                     oonm::Vector<oonm::Vector<T>>& R);
};

#include "qr_decomp.hpp"


#endif /* QR_DECOMP_H_ */
