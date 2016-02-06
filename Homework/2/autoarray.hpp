//////////////////////////////////////////////////////////////////////
/// @file array.hpp
/// @author Ryan J. Krattiger (rjk9w5) 
/// @brief BRIEF_DESCRIPTION_HERE
//////////////////////////////////////////////////////////////////////
#ifndef AUTOARRAY_HPP_
#define AUTOARRAY_HPP_

#include <exception>
#include <algorithm>
#include <cstddef>

template<class T>
class autoArray
{
  public:
//    typedef const T* iterator;

    autoArray();
    autoArray(const int size);
    autoArray(const int size, const T& value);
    autoArray(const autoArray<T>& src);
    ~autoArray();

//    iterator end() const;
//    iterator begin() const;

    void resize(const int size);
    void reuse();
    void setSize(const int size);
    const T& operator[](const int i) const;
    T& operator[](const int i);

    autoArray<T>& operator=(const autoArray<T>& src);

    void sort();
  private:
    int m_size, m_max;
    T* m_data;
};

#include "autoArray.tpp"

#endif /* AUTOARRAY_HPP_ */
