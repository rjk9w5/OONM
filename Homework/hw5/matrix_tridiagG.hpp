/* ************************************************************************** *\
 * matrix_tridiagG.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */

//template <class Ele_T>
//std::shared_ptr<oonm::Matrix_type<Ele_T>>
//  operator + (
//      MatrixTriDiag<Ele_T> const &m1,
//      Matrix_type<Ele_T> const &m2)
//{
//  if(m1.N() == m2.N() &&
//     m1.M() == m2.M())
//  {
//    // Less efficient, but allows for conversion to any matrix type
//    // via a assignment/constructor using the Matrix_type shared pointer!
//    std::shared_ptr<oonm::Matrix_type<Ele_T>> cpy = m1.clone();
//
//    for(std::size_t i=0; i<m1.N(); ++i)
//    {
//      for(std::size_t j=0; j<m1.M(); ++j)
//      {
//        cpy -> operator()(i,j) = m1(i,j) + m2(i,j);
//      }
//    }
//    return cpy;
//  }
//  else
//    throw oonm::DimensionMismatch();
//}

//template <class Ele_T>
//std::shared_ptr<oonm::Matrix_type<Ele_T>>
//  operator - (
//      MatrixTriDiag<Ele_T> const &m1,
//      Matrix_type<Ele_T> const &m2);
//
//template <class Ele_T>
//std::shared_ptr<oonm::Matrix_type<Ele_T>>
//  operator * (
//      MatrixTriDiag<Ele_T> const &m1,
//      Matrix_type<Ele_T> const &m2);
//
//template <class Ele_T>
//std::shared_ptr<oonm::Matrix_type<Ele_T>>
//  operator + (
//      Matrix_type<Ele_T> const &m1,
//      MatrixTriDiag<Ele_T> const &m2);
//
//template <class Ele_T>
//std::shared_ptr<oonm::Matrix_type<Ele_T>>
//  operator - (
//      Matrix_type<Ele_T> const &m1,
//      MatrixTriDiag<Ele_T> const &m2);
//
//template <class Ele_T>
//std::shared_ptr<oonm::Matrix_type<Ele_T>>
//  operator * (
//      Matrix_type<Ele_T> const &m1,
//      MatrixTriDiag<Ele_T> const &m2);
//
//template <class Ele_T>
//oonm::Vector<Ele_T>
//  operator * (
//      MatrixTriDiag<Ele_T> const &mat,
//      Vector<Ele_T> const &v);


template <class Ele_T>
void
oonm::swap(
    MatrixTriDiag<Ele_T> &m1,
    MatrixTriDiag<Ele_T> &m2)
{
  using std::swap;

  swap(m1.data_,m2.data_);
  swap(m1.n_,m2.n_);

  return;
}
