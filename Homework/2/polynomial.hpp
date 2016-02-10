//////////////////////////////////////////////////////////////////////
/// @file polynomial.hpp
/// @author Ryan John Krattiger
/// @brief File contains declarations for a polynomial class
////////////////////////////////////////////////////////////////////// 

#ifndef POLYNOMIAL_HPP_
#define POLYNOMIAL_HPP_

//////////////////////////////////////////////////////////////////////
/// @class Polynomial
/// @brief Encapsulation of a polynomial
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::Polynomial()
/// @brief Default Constructor for Polynomial object
/// @post Initializes an empty Polynomial object
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::Polynomial(const Polynomial<T>& src)
/// @brief Copy constructor for Polynomial object
/// @post Initializes a copy of Polynomial object
/// @param Polynomial object to be copied
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator +=
/// @brief Plus equals operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator +
/// @brief Addition operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator -=
/// @brief Minus equals operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator -
/// @brief Subtraction operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator -
/// @brief Unary negation operator
/// @pre 
/// @post 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator ~
/// @brief Negation operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator ==
/// @brief Equality operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator !=
/// @brief Non-equality operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator =
/// @brief Assignment operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator [] const
/// @brief Bracket accessor
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator []
/// @brief Bracket mutator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Polynomial::operator ()
/// @brief Functor for polynomial evaluation
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn (friend) operator <<
/// @brief Output operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn (friend) operator >>
/// @brief Input operator
/// @pre 
/// @post 
/// @param 
/// @return 
//////////////////////////////////////////////////////////////////////


#include <ostream>
#include <istream>
#include <string>
#include "myExceptions.hpp"
#include <cmath>
#include "autoarray.hpp"
#include "monomial.hpp"

template <class T>
class Polynomial;

template <class T>
std::ostream& operator<< (std::ostream& out, const Polynomial<T> &p);
template <class T>
std::istream& operator>> (std::istream& in, Polynomial<T> &p);

template <class T>
bool operator==(const Polynomial<T>& lhs, const Polynomial<T> &rhs);
template <class T>
bool operator!=(const Polynomial<T>& lhs, const Polynomial<T> &rhs);

template <class T>
class Polynomial
{
  public:
//    typedef autoArray<monomial<T> >::iterator iterator;

    Polynomial();
    Polynomial<T>& operator=(const Polynomial<T> &rhs);
    Polynomial(const Polynomial<T>& src);
    ~Polynomial();
    
    const int get_nterms() const {return m_data.get_size();}
    void simplify();

//    typename iterator begin() const;
//    typename iterator end() const;

    // Simple Math
    const Polynomial<T>& operator+=(const Polynomial<T> &rhs);

    const Polynomial<T> operator+(
        const Polynomial<T> &rhs) const;

    const Polynomial<T>& operator-=(const Polynomial<T> &rhs);
    
    const Polynomial<T> operator-(
        const Polynomial<T> &rhs) const;

    // Unary
    const Polynomial<T> operator-() const;
    const Polynomial<T> operator~() const;
    
    // Access
    monomial<T>& operator[](const int i);
    const monomial<T>& operator[](const int i) const;

    // Evaluate
    T operator()(const T x) const;

    // Compare
    friend bool operator==<>(
        const Polynomial<T>& lhs,
        const Polynomial<T> &rhs);

    friend bool operator!=<>(
        const Polynomial<T>& lhs,
        const Polynomial<T> &rhs);
    // IO
    friend std::ostream& operator<< <>(
        std::ostream& out,
        const Polynomial<T> &p);

    friend std::istream& operator>> <>(
        std::istream& in,
        Polynomial<T> &p);

  private:
    auto_array<monomial<T> > m_data; // Holds values of coefficients
};

#include "polynomial.tpp"

#endif
