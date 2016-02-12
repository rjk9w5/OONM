/*
 * monomial.hpp
 *
 *  Created on: Feb 6, 2016
 *      Author: ryan
 *       Brief: Declaration of monomial template class and associated
 *              friend functions
 */

/*
 *       class: monomial
 *       brief: Template class to store information for and perform operations
 *              of polynomial type functions.
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
 */

/*
 *    function:
 *       brief:
 *        post:
 *       param:
 *      return:
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
bool operator ==(const monomial<T>& lhs, const monomial<T>& rhs);
template <class T>
bool operator !=(const monomial<T>& lhs, const monomial<T>& rhs);

template <class T>
class monomial
{
  public:

    const T& get_order() const {return m_order;}
    const T& get_coeff() const {return m_coeff;}
    void set_order(const T& order) {m_order = order; return;}
    void set_coeff(const T& coeff) {m_coeff = coeff; return;}

    // for sorting
    bool operator < (const monomial<T>& cmp) const;

    monomial<T>& operator =(const monomial<T>& src);

    friend std::ostream& operator << <>(std::ostream& out,
                                        const monomial<T>& data);
    friend std::istream& operator >> <>(std::istream& out,
                                         monomial<T>& data);

    friend bool operator ==<>(const monomial<T>& lhs, const monomial<T>& rhs);
    friend bool operator !=<>(const monomial<T>& lhs, const monomial<T>& rhs);

    const T operator()(const T& x) const;

  private:
    T m_coeff;
    T m_order;
};

#include "monomial.tpp"

#endif /* HOMEWORK_2_MONOMIAL_HPP_ */
