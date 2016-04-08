/*
 * matrix.h
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#ifndef HOMEWORK_HW5_MATRIX_H_
#define HOMEWORK_HW5_MATRIX_H_

#include <memory>
#include <iostream>

namespace oonm
{
  template <class Ele_T>
  class Matrix_type;

  template <class Ele_T>
  std::shared_ptr<oonm::Matrix_type<Ele_T>>
    operator + (
        Matrix_type<Ele_T> const &m1,
        Matrix_type<Ele_T> const &m2);

//  template <class Ele_T>
//  void swap(Matrix_type<Ele_T> &m1, Matrix_type<Ele_T> &m2);

  template <class Ele_T>
  class Matrix_type
  {
    public:
      virtual ~Matrix_type() {}

      virtual inline Ele_T&
      operator ()(
          std::size_t const i,
          std::size_t const j) = 0;

      virtual inline Ele_T const &
      operator ()(
          std::size_t const i,
          std::size_t const j) const = 0;

      virtual inline std::shared_ptr<Matrix_type<Ele_T>>
      clone() const = 0;

      virtual inline bool
      checki(
          std::size_t const i) const = 0;

      virtual inline bool
      checkj(
          std::size_t const i) const = 0;

      virtual inline std::size_t
      get_nrows() const = 0;

      virtual inline std::size_t
      get_ncols() const = 0;

      virtual inline void
      set_size(
          std::size_t const n,
          std::size_t const m) = 0;
  };
}; // oonm namespace

#include "matrix_typeG.hpp"

#endif /* HOMEWORK_HW5_MATRIX_H_ */
