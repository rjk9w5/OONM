/*
 * matrix_typeG.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#include "matrix_dense.h"

template <class Ele_T>
std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::operator + (
      Matrix_type<Ele_T> const &m1,
      Matrix_type<Ele_T> const &m2)
{
  if(m1.N() == m2.N() &&
     m1.M() == m2.M())
  {
    // Less efficient, but allows for conversion to any matrix type
    // via a assignment/constructor using the Matrix_type shared pointer!
    std::shared_ptr<oonm::Matrix_type<Ele_T>> cpy = m1.clone();

    for(std::size_t i=0; i<m1.N(); ++i)
    {
      for(std::size_t j=0; j<m1.M(); ++j)
      {
        cpy -> operator()(i,j) = m1(i,j) + m2(i,j);
      }
    }
    return cpy;
  }
  else
    throw oonm::DimensionMismatch();
}

template <class Ele_T>
std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::operator - (
      Matrix_type<Ele_T> const &m1,
      Matrix_type<Ele_T> const &m2)
{
  if(m1.N() == m2.N() &&
     m1.M() == m2.M())
  {
    std::shared_ptr<oonm::Matrix_type<Ele_T>> cpy = m1.clone();

    for(std::size_t i=0; i<m1.N(); ++i)
    {
      for(std::size_t j=0; j<m1.M(); ++j)
      {
        cpy -> operator()(i,j) = m1(i,j) - m2(i,j);
      }
    }
    return cpy;
  }
  else
    throw oonm::DimensionMismatch();
}

template <class Ele_T>
std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::operator * (
      Matrix_type<Ele_T> const &m1,
      Matrix_type<Ele_T> const &m2)
{
  if(m1.M()  == m2.N())
  {
    std::shared_ptr<oonm::Matrix_type<Ele_T>> cpy = m1.clone();

    cpy -> set_size(m1.N(), m2.M());
    for(std::size_t i=0; i<m1.N(); ++i)
    {
      for(std::size_t j=0; j<m2.M(); ++j)
      {
        cpy -> operator()(i,j) = 0;
        for(std::size_t k=0; k<m1.N(); ++k)
        {
          cpy -> operator()(i,j) += m1(i,k)*m2(k,j);
        }
      }
    }
    return cpy;
  }
  else
    throw oonm::DimensionMismatch();
}

template <class Ele_T>
oonm::Vector<Ele_T>
  oonm::operator * (
      Matrix_type<Ele_T> const &mat,
      Vector<Ele_T> const &v)
{
  if(mat.M()  == v.get_size())
  {
    Vector<Ele_T> ret(v.get_size());

    for(std::size_t i=0; i<mat.N(); ++i)
    {
      ret[i] = 0;
      for(std::size_t k=0; k<mat.M(); ++k)
      {
        ret[i] += mat(i,k)*v[k];
      }
    }
    return ret;
  }
  else
    throw oonm::DimensionMismatch();
}

template <class Ele_T>
std::ostream&
oonm::operator << (
    std::ostream &out,
    Matrix_type<Ele_T> const &mat)
{
  mat.print(out);

  return out;
}

