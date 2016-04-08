/*
 * dense_matrix.h
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#ifndef HOMEWORK_HW5_DENSE_MATRIX_H_
#define HOMEWORK_HW5_DENSE_MATRIX_H_

#include <utility>
#include "matrix_type.h"
#include "vector.h"
#include "exceptions.h"

namespace oonm
{
  template <class Ele_T>
  class MatrixDense;

  template <class Ele_T>
  void
  swap(
      MatrixDense<Ele_T> &m1,
      MatrixDense<Ele_T> &m2);

  template <class Ele_T>
  class MatrixDense: public virtual oonm::Matrix_type<Ele_T>
  {
      public:
        MatrixDense() = default;

        MatrixDense(
            std::size_t const i,
            std::size_t const j);

        MatrixDense(
            MatrixDense<Ele_T> const &src);

        MatrixDense(
            MatrixDense<Ele_T> &&other);

        MatrixDense<Ele_T>&
        operator = (
            MatrixDense<Ele_T> src);

        MatrixDense<Ele_T>&
        operator = (
            std::shared_ptr<oonm::Matrix_type<Ele_T>> const src);

        virtual ~MatrixDense() {}

        virtual inline Ele_T&
        operator ()(
            std::size_t const i,
            std::size_t const j);

        virtual inline Ele_T const &
        operator ()(
            std::size_t const i,
            std::size_t const j) const;

        virtual inline std::shared_ptr<Matrix_type<Ele_T>>
        clone() const;

        virtual inline bool
        checki(
            std::size_t const i) const;

        virtual inline bool
        checkj(
            std::size_t const i) const;

        virtual inline std::size_t
        N() const;

        virtual inline std::size_t
        M() const;

        virtual void
        swapr(
            std::size_t const r1,
            std::size_t const r2);

        virtual void
        swapc(
            std::size_t const c1,
            std::size_t const c2);

        virtual inline void
        set_size(
            std::size_t const n,
            std::size_t const m);

        virtual void print(std::ostream& out) const;

        friend void
        swap <> (
            MatrixDense<Ele_T> &m1,
            MatrixDense<Ele_T> &m2);
      private:
        oonm::Vector<Ele_T> data_;
        std::size_t n_;
        std::size_t m_;
    };
}; // oonm namespace

#include "matrix_denseI.hpp"

#endif /* HOMEWORK_HW5_DENSE_MATRIX_H_ */
