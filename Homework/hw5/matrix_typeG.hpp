/*
 * matrix_typeG.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */


template <class Ele_T>
std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::operator + (
      oonm::Matrix_type<Ele_T> const &m1,
      Matrix_type<Ele_T> const &m2)
{
  std::shared_ptr<oonm::Matrix_type<Ele_T>> cpy = m1.clone();

  if(m1.get_nrows() == m2.get_nrows() &&
     m1.get_ncols() == m2.get_ncols())
  {
    std::cout << cpy -> get_nrows() << '\n';
    for(std::size_t i=0; i<m1.get_nrows(); ++i)
    {
      for(std::size_t j=0; j<m1.get_ncols(); ++j)
      {
        cpy -> operator()(i,j) = m1(i,j) + m2(i,j);
      }
    }
  }
  else
    throw oonm::DimensionMismatch();

  return cpy;
}

template <class Ele_T>
std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::operator - (
      oonm::Matrix_type<Ele_T> const &m1,
      Matrix_type<Ele_T> const &m2)
{
  std::shared_ptr<oonm::Matrix_type<Ele_T>> cpy = m1.clone();

  if(m1.get_nrows() == m2.get_nrows() &&
     m1.get_ncols() == m2.get_ncols())
  {
    std::cout << cpy -> get_nrows() << '\n';
    for(std::size_t i=0; i<m1.get_nrows(); ++i)
    {
      for(std::size_t j=0; j<m1.get_ncols(); ++j)
      {
        cpy -> operator()(i,j) = m1(i,j) - m2(i,j);
      }
    }
  }
  else
    throw oonm::DimensionMismatch();

  return cpy;
}

template <class Ele_T>
std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::operator * (
      oonm::Matrix_type<Ele_T> const &m1,
      Matrix_type<Ele_T> const &m2)
{
  std::shared_ptr<oonm::Matrix_type<Ele_T>> cpy = m1.clone();

  if(m1.get_ncols()  == m2.get_nrows())
  {
    cpy -> set_size(m1.get_nrows(), m2.get_ncols());
    for(std::size_t i=0; i<m1.get_nrows(); ++i)
    {
      for(std::size_t j=0; j<m2.get_ncols(); ++j)
      {
        for(std::size_t k=0; k<m1.get_ncols(); ++k)
        {
          cpy -> operator()(i,j) += m1(i,k)*m2(k,j);
        }
      }
    }
  }
  else
    throw oonm::DimensionMismatch();

  return cpy;
}

