/*
 * matrix_tridiag.h
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#ifndef HOMEWORK_HW5_MATRIX_TRIDIAG_H_
#define HOMEWORK_HW5_MATRIX_TRIDIAG_H_

#include "matrix_dense.h"

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
        MatrixTriDiag(std::size_t const nm);
        MatrixTriDiag(MatrixTriDiag<Ele_T> const &src);
        MatrixTriDiag(MatrixTriDiag<Ele_T> &&other);
        MatrixTriDiag<Ele_T>& operator = (MatrixTriDiag<Ele_T> src);
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

        virtual inline bool checki(std::size_t const i) const;
        virtual inline bool checkj(std::size_t const i) const;

        friend void
        swap <> (
            MatrixTriDiag<Ele_T> &m1,
            MatrixTriDiag<Ele_T> &m2);
      private:
        oonm::MatrixDense<Ele_T> data_;
        std::size_t r_;
        std::size_t c_;
    };
}; // oonm namespace



#endif /* HOMEWORK_HW5_MATRIX_TRIDIAG_H_ */
