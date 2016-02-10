//////////////////////////////////////////////////////////////////////
/// @file array.hpp
/// @author Ryan J. Krattiger (rjk9w5) 
/// @brief An array class to assist with operations in polynomial
//////////////////////////////////////////////////////////////////////
#ifndef AUTOARRAY_HPP_
#define AUTOARRAY_HPP_

#include <exception>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <memory>

template <class T>
class auto_array;

template <class T>
bool operator == (const auto_array<T>& lhs, const auto_array<T>& rhs);
template <class T>
bool operator != (const auto_array<T>& lhs, const auto_array<T>& rhs);
template <class T>
auto_array<T>& cat(const auto_array<T>& a1, const auto_array<T>& a2);

template<class T>
class auto_array
{
  public:
//    typedef const T* iterator;

    auto_array();
    auto_array(const int size);
    auto_array(const int size, const T& value);
    auto_array(const auto_array<T>& src);
    ~auto_array();

//    iterator end() const;
//    iterator begin() const;

    void resize(const int size);

    void reuse();

    void reuse(const int size);

    void set_size(const int size);

    const int get_size() const {return m_size;}

    void remove(const int i);

    friend auto_array<T>& cat<>(
        const auto_array<T>& a1,
        const auto_array<T>& a2);

    const T& operator[](const int i) const;

    T& operator[](const int i);

    auto_array<T>& operator=(const auto_array<T>& src);
    void sort();

    friend bool operator == <>(
        const auto_array<T>& lhs,
        const auto_array<T>& rhs);

    friend bool operator != <>(
        const auto_array<T>& lhs,
        const auto_array<T>& rhs);

  private:
    int m_size, m_max;
    std::unique_ptr<T[]> m_data;
};

#include "autoarray.tpp"

#endif /* AUTOARRAY_HPP_ */
