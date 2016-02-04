//////////////////////////////////////////////////////////////////////
/// @file array.hpp
/// @author Ryan J. Krattiger (rjk9w5) 
/// @brief BRIEF_DESCRIPTION_HERE
//////////////////////////////////////////////////////////////////////
#ifndef AUTOARRAY_HPP_
#define AUTOARRAY_HPP_

#include <exception>

template<class T>
class autoArray
{
  public:
    autoArray(){};
    autoArray(const int size);
    autoArray(const T& value);
    autoArray(const autoArray<T>& src);
    ~autoArray();

    const T& operator[](const int i);

  private:
    int m_size, m_max;
    T* m_data;
    void arraycpy(const autoArray<T>& src);
};



#endif /* AUTOARRAY_HPP_ */
