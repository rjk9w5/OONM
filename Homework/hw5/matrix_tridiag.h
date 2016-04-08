/*
 * matrix_tridiag.h
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#ifndef HOMEWORK_HW5_MATRIX_TRIDIAG_H_
#define HOMEWORK_HW5_MATRIX_TRIDIAG_H_

#include <utility>
#include "matrix_type.h"
#include "vector.h"
#include "exceptions.h"

namespace oonm
{
  template <class Ele_T>
  class MatrixTriDiag;

  template <class Ele_T>
  void
  swap(
      MatrixTriDiag<Ele_T> &m1,
      MatrixTriDiag<Ele_T> &m2);

  template <class Ele_T>
  class MatrixTriDiag: public virtual oonm::Matrix_type<Ele_T>
  {
      public:
      MatrixTriDiag() = default;

      MatrixTriDiag(
            std::size_t const n);

      MatrixTriDiag(
          Vector<Ele_T> const &vneg1,
          Vector<Ele_T> const &v0,
          Vector<Ele_T> const &v1);

      MatrixTriDiag(
          MatrixTriDiag<Ele_T> const &src);

      MatrixTriDiag(
          MatrixTriDiag<Ele_T> &&other);

      MatrixTriDiag<Ele_T>&
        operator = (
            MatrixTriDiag<Ele_T> src);

      MatrixTriDiag<Ele_T>&
        operator = (
            std::shared_ptr<oonm::Matrix_type<Ele_T>> const src);

        virtual ~MatrixTriDiag() {}

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
            std::size_t const r1,
            std::size_t const r2);

        virtual inline void
        set_size(
            std::size_t const n,
            std::size_t const m);

        inline void
        set_size(
            std::size_t const n);

        virtual void print(std::ostream& out) const;

        friend void
        swap <> (
            MatrixTriDiag<Ele_T> &m1,
            MatrixTriDiag<Ele_T> &m2);
      private:
        oonm::Vector<Ele_T> data_;
        std::size_t n_;
        Ele_T vempty = 0;
        Ele_T const cempty = 0;
    };
}; // oonm namespace

#include "matrix_tridiagG.hpp"
#include "matrix_tridiagI.hpp"



#endif /* HOMEWORK_HW5_MATRIX_TRIDIAG_H_ */
