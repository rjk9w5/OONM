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
#include <iomanip>
#include "vector.h"

namespace oonm
{
  template <class Ele_T>
  class Matrix_type;

  template <class Ele_T>
  std::shared_ptr<oonm::Matrix_type<Ele_T>>
    operator + (
        Matrix_type<Ele_T> const &m1,
        Matrix_type<Ele_T> const &m2);

  template <class Ele_T>
  std::shared_ptr<oonm::Matrix_type<Ele_T>>
    operator - (
        Matrix_type<Ele_T> const &m1,
        Matrix_type<Ele_T> const &m2);

  template <class Ele_T>
  std::shared_ptr<oonm::Matrix_type<Ele_T>>
    operator * (
        Matrix_type<Ele_T> const &m1,
        Matrix_type<Ele_T> const &m2);

  template <class Ele_T>
  oonm::Vector<Ele_T>
    operator * (
        Matrix_type<Ele_T> const &mat,
        Vector<Ele_T> const &v);

  template <class Ele_T>
  std::ostream&
  operator << (
      std::ostream &out,
      Matrix_type<Ele_T> const &mat);


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
      N() const = 0;

      virtual inline std::size_t
      M() const = 0;

      virtual void
      swapr(
          std::size_t const r1,
          std::size_t const r2) = 0;

      virtual void
      swapc(
          std::size_t const c1,
          std::size_t const c2) = 0;

      virtual inline void
      set_size(
          std::size_t const n,
          std::size_t const m) = 0;

      virtual void print(std::ostream& out) const = 0;
  };
}; // oonm namespace

#include "matrix_typeG.hpp"

#endif /* HOMEWORK_HW5_MATRIX_H_ */
