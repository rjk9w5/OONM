/*
 * monomial.hpp
 *
 *  Created on: Feb 6, 2016
 *      Author: ryan
 */

#ifndef HOMEWORK_2_MONOMIAL_HPP_
#define HOMEWORK_2_MONOMIAL_HPP_

#include <cmath>
#include <ostream>
#include <istream>
#include "myExceptions.hpp"

template <class T>
class monomial;

template <class T>
std::ostream& operator <<
    (std::ostream& out, const monomial<T>& data);

template <class T>
std::istream& operator >>
    (std::istream& out, monomial<T>& data);

template <class T>
class monomial
{
  public:

    T& getOrder() const {return m_order;}
    T& getCoeff() const {return m_coeff;}
    void setOrder(const T& order) {m_order = order; return;}
    void setCoeff(const T& coeff) {m_coeff = coeff; return;}

    bool operator < (const monomial<T>& cmp) const
    {
      return m_order < cmp.m_order;
    }

    monomial<T>& operator =(const monomial<T>& src)
    {
      m_order = src.m_order;
      m_coeff = src.m_coeff;
      return *this;
    }

    friend std::ostream& operator << <T>(std::ostream& out,
                                        const monomial<T>& data);
    friend std::istream& operator >> <T>(std::istream& out,
                                         monomial<T>& data);

    double operator()(const double x) const
    {
      double ret;
      ret = m_coeff*pow(x,m_order);
      return ret;
    }

  private:
    T m_coeff;
    T m_order;
};


template <class T>
std::ostream& operator <<
    (std::ostream& out, const monomial<T>& data)
{
  if(data.m_coeff < 0)
  {
    out << "- " << -data.m_coeff;
  }
  else
  {
    out << "+ " << data.m_coeff;
  }
  if(data.m_order > 0)
    out << '^' << data.m_order;

  out << ' ';

  return out;
}

template <class T>
std::istream& operator >>
    (std::istream& in, monomial<T>& data)
{
  // Get next term coefficient
  in >> data.m_coeff;

  if(in.get() == '\n') throw file_error("Incorrect input format.");
  in.unget();

  in >> data.m_order;

  return in;
}

#endif /* HOMEWORK_2_MONOMIAL_HPP_ */
