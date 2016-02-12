/*
 * autoArray.tpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Declaration of polynomial template class and associated
 *              friend functions
 */

/*
 *       class: polynomail_fnct
 *       brief: Template class to store information for and perform operations
 *              of polynomial type functions.
 */

/*
 *    function: polynomail_fnct()
 *       brief: Default constructor
 *        post: Allocates memory for a polynomial_fnct object.
 */

/*
 *    function: polynomail_fnct(const T& coeff, const T& order)
 *       brief: Constructor for a monomial
 *        post: Constructs a monomial form input
 *   parameter: coefficient of monomial
 *   parameter: order of the monomail
 */

/*
 *    function: polynomail_fnct(const polynomail_fnct<T>&)
 *       brief: Copy constructor
 *        post: Allocates memory for a polynomial_fnct object with same values
 *              found in input.
 *   parameter: polynomail_fnct object to be copied into new polynomial_fnct
 */

/*
 *    function: polynomail_fnct(polynomail_fnct<T>&&)
 *       brief: Move constructor
 *        post: Moves memory for a new polynomial_fnct object with same values
 *              found in input.
 *   parameter: polynomail_fnct object to be moved into new polynomial_fnct
 */

/*
 *    function: operator=(const polynomail_fnct<T>&)
 *       brief: Copy assignment
 *        post: Assigns "this" the same values found in input by copy.
 *   parameter: polynomail_fnct object to be copied into new polynomial_fnct
 *      return: Value of calling object (polynomial_fnct).
 */

/*
 *    function: operator=(polynomail_fnct<T>&&)
 *       brief: Move assignment
 *        post: Assigns "this" the same values found in input by move semantics.
 *   parameter: polynomail_fnct object to be moved into new polynomial_fnct
 *      return: Value of calling object (polynomial_fnct).
 */

/*
 *    function: operator*(const T& C)
 *       brief: Multiplication polynomial_fnct*C
 *        post: Returns product of C and calling polynomial_fnct object
 *   parameter: Constant multiplier
 *      return: Returns product of C and calling polynomial_fnct object
 *              (polynomial_fnct)
 */

/*
 *    function: operator*(const T& C, const polynomail_fnct<T>& p)
 *       brief: Multiplication C*polynomial_fnct
 *        post: Returns product of C and calling polynomial_fnct object
 *   parameter: Constant multiplier
 *   parameter: polynomail_fnct object to be multiplied
 *      return: Returns product of C and calling polynomial_fnct object
 *              (polynomial_fnct)
 */

/*
 *    function: operator+=(const polynomail_fnct<T>&)
 *       brief: Addition and assignment
 *        post: Assigns calling object the sum of the input and the calling
 *              object.
 *   parameter: polynomail_fnct object to be added to "this"
 *      return: calling object (polynomial_fnct)
 */

/*
 *    function: operator+(const polynomail_fnct<T>&)
 *       brief: Addition
 *        post: Sums the input and the calling object.
 *   parameter: polynomail_fnct object to be added to calling object.
 *      return: Value of sum of input and calling object (polynomial_fnct).
 */

/*
 *    function: operator-=(polynomail_fnct<T>&)
 *       brief: Subtraction and assignment
 *        post: Assigns calling object the difference of the input and the
 *        calling object.
 *   parameter: polynomail_fnct object to be subtracted to "this"
 *      return: calling object (polynomial_fnct).
 */

/*
 *    function: operator-(polynomail_fnct<T>&)
 *       brief: Subtraction
 *        post: Subtracts the input from the calling object.
 *   parameter: polynomail_fnct object to be subtracted from calling object.
 *      return: Value of difference of input and calling object
 *              (polynomial_fnct).
 */

/*
 *    function: operator-()
 *       brief: Negation
 *        post: Negates the calling object.
 *      return: Value of the negation of the calling object (polynomial_fnct).
 */

/*
 *    function: operator~()
 *       brief: Useless overload that makes all coefficients negative.
 *        post: Makes a polynomial_fnct object with coefficients negative from calling.
 *      return: Value of the ~ of the calling object (polynomial_fnct).
 */

/*
 *    function: operator==(const polynomial_fnct<T>&,const polynomial<T>&)
 *       brief: Check if polynomial_fnct one is equal to polynomial_fnct two.
 *        post: Returns result of comparison.
 *       param: polynomial_fnct one
 *       param: polynomial_fnct two
 *      return: True if the values are equal, otherwise false.
 */

/*
 *    function: operator!=(const polynomial_fnct<T>&,const polynomial<T>&)
 *       brief: Check if polynomial_fnct one is not equal to polynomial_fnct
 *              two.
 *        post: Returns result of comparison.
 *       param: polynomial_fnct one.
 *       param: polynomial_fnct two.
 *      return: True if the values are not equal, otherwise false.
 */

/*
 *    function: operator [](const int i) const
 *       brief: read-only element access operator.
 *        post: returns a monomial type of the ith term in the polynomial_fnct
 *              calling object.
 *       param: integer value corresponding to the term in the polynomial that
 *              is to be accessed.
 *      return: monomial type of the ith term in the polynomial_fnct calling
 *              object.
 */

/*
 *    function: operator [](const int i)
 *       brief: read-write element access operator.
 *        post: returns a monomial type of the ith term in the polynomial_fnct
 *              calling object.
 *       param: integer value corresponding to the term in the polynomial that
 *              is to be accessed.
 *      return: monomial type of the ith term in the polynomial_fnct calling
 *              object.
 */

/*
 *    function: operator ()(const T&)
 *       brief: Functor for evaluation of polynomial.
 *        post: Evaluates the polynomial_fnct at some value of 'x'.
 *       param: The 'x' value to evaluate at.
 *      return: The value found from evaluating the calling object at 'x' (T)
 */

/*
 *    function: (friend) operator << (std::ostream&, const polynomial_fnct<T>&)
 *       brief: Output operator to be used the the std::ostream object to
 *              output to screen.
 *        post: Outputs a polynomial_fnct object to screen.
 *       param: std::ostream object.
 *       param: polynomial_fnct object to be put to screen.
 *      return: std::ostream object.
 */

/*
 *    function: (friend) operator >> (std::istream&, polynomial_fnct<T>&)
 *       brief: Input operator to be used the the std::istream object to read
 *              a polynomial_fnct object.
 *        post: Reads a polynomial_fnct object.
 *       param: std::istream object.
 *       param: polynomial_fnct object to be read into.
 *      return: std::istream object.
 */

/*
 *    function: magnitude()
 *       brief: Calculate the magnitude of the polynomial_fnct object
 *        post: Calculates the magnitude per assignment description:
 *              ie.
 *                1 + 2*x^2 + 2*x^3 has magnitude of sqrt(1^2 + 2^2 + 2^2) =
 *      return: The magnitude of the calling polynomial_fnct object (double)
 */

/*
 *    function: get_nterms()
 *       brief: Getter for the number of terms in the polynomial_fnct.
 *        post: returns and integer of number of terms.
 *      return: integer of number of terms.
 */

/*
 *    function: (private) simplify()
 *       brief: Will reduce polynomial_fnct object to least number of terms ie.
 *              no duplicate terms of same order.
 *        post: Reduces
 *      return: void
 */

#ifndef POLYNOMIAL_HPP_
#define POLYNOMIAL_HPP_

// Includes (maybe more than is needed now but I didn't check)
#include <ostream>
#include <istream>
#include <string>
#include <exception>
#include <cmath>
#include <utility>
#include "autoarray.hpp"

template <class T>
class polynomial_fnct;

template <class T>
const polynomial_fnct<T> operator*(const T& C, const polynomial_fnct<T>& p);

template <class T>
std::ostream& operator<< (std::ostream& out, const polynomial_fnct<T> &p);
template <class T>
std::istream& operator>> (std::istream& in, polynomial_fnct<T> &p);

template <class T>
bool operator==(const polynomial_fnct<T>& lhs, const polynomial_fnct<T> &rhs);
template <class T>
bool operator!=(const polynomial_fnct<T>& lhs, const polynomial_fnct<T> &rhs);

template <class T>
class polynomial_fnct
{
  public:
//    typedef autoArray<monomial<T> >::iterator iterator;

    polynomial_fnct();
    polynomial_fnct(const T& coeff, const T& order);
    polynomial_fnct<T>& operator=(const polynomial_fnct<T> &rhs);
    polynomial_fnct(const polynomial_fnct<T> &src);
    polynomial_fnct<T>& operator=(polynomial_fnct<T> &&rhs);
    polynomial_fnct(polynomial_fnct<T> &&other);
    ~polynomial_fnct();
    
    const int get_nterms() const {return m_data.get_size();}
    double magnitude() const;

//    typename iterator begin() const;
//    typename iterator end() const;

    // Simple Math
    const polynomial_fnct<T> operator*(const T& C) const;

    const polynomial_fnct<T>& operator+=(const polynomial_fnct<T> &rhs);

    const polynomial_fnct<T> operator+(
        const polynomial_fnct<T> &rhs) const;

    const polynomial_fnct<T>& operator-=(const polynomial_fnct<T> &rhs);
    
    const polynomial_fnct<T> operator-(
        const polynomial_fnct<T> &rhs) const;

    // Unary
    const polynomial_fnct<T> operator-() const;
    const polynomial_fnct<T> operator~() const;
    
    // Access
    const polynomial_fnct<T> operator[](const int i) const;

    // Evaluate
    T operator()(const T& x) const;

    // Compare
    friend bool operator==<>(
        const polynomial_fnct<T>& lhs,
        const polynomial_fnct<T> &rhs);

    friend bool operator!=<>(
        const polynomial_fnct<T>& lhs,
        const polynomial_fnct<T> &rhs);
    // IO
    friend std::ostream& operator<< <>(
        std::ostream& out,
        const polynomial_fnct<T> &p);

    friend std::istream& operator>> <>(
        std::istream& in,
        polynomial_fnct<T> &p);

    struct term
    {
      T m_coeff, m_order;

      // For sorting
      bool operator < (const term& cmp) const
      {
        return m_order < cmp.m_order;
      }

      term& operator =(const term& src)
      {
        m_coeff = src.m_coeff;
        m_order = src.m_order;
      }

      bool operator ==(const term& rhs) const
      {
        return (m_coeff == rhs.m_coeff && m_order == rhs.m_order);
      }
      bool operator !=(const term& rhs) const
      {
        return !(*this == rhs);
      }

      const T operator()(const T& x) const
      {
        return m_coeff*pow(x,m_order);
      }
    };

  private:
    auto_array<term> m_data; // Holds values of coefficients
    void simplify();
};

#include "polynomial.tpp"

#endif
