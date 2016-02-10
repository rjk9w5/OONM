/*
 * monomial.hpp
 *
 *  Created on: Feb 6, 2016
 *      Author: ryan
 *  Description:
 */

#ifndef HOMEWORK_2_MONOMIAL_HPP_
#define HOMEWORK_2_MONOMIAL_HPP_

#include <cmath>
#include <iostream>
#include <cstdlib>

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

    const T& get_order() const {return m_order;}
    const T& get_coeff() const {return m_coeff;}
    void set_order(const T& order) {m_order = order; return;}
    void set_coeff(const T& coeff) {m_coeff = coeff; return;}

    // for sorting
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
std::ostream& operator << (
    std::ostream& out,
    const monomial<T>& data)
{
  T c, o;
  c = data.m_coeff;
  o = data.m_order;
  if(data.m_coeff != 0)
  {
    if(o == 0)
    {
      if(c>0) out << '+' << ' ' << c;
      else out << '-' << ' ' << -c;
    }
    else if(o==1)
    {
      if(c==1 || c==-1)
      {
        out << (c>0?'+':'-') << ' ' << 'x';
      }
      else
      {
        out << (c>0?'+':'-') << ' ' << (c>0?c:-c) << '*' << 'x';
      }
    }
    else
    {
      if(c==1 || c==-1)
      {
        out << (c>0?'+':'-') << ' ' << 'x';
      }
      else
      {
        out << (c>0?'+':'-') << ' ' << (c>0?c:-c) << '*' << 'x';
      }
      out << '^' << o;
    }
    out << ' ';
  }

  return out;
}

template <class T>
std::istream& operator >>(
    std::istream& in,
    monomial<T>& data)
{
  // Get next term coefficient
  in >> data.m_coeff;

  if(in.get() == '\n')
  {
    throw std::invalid_argument("read monomial: pair not found\n");
  }
  in.unget();

  in >> data.m_order;

  return in;
}

#endif /* HOMEWORK_2_MONOMIAL_HPP_ */
