/*
 * autoArray.tpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Declarations of auto_array template class and associated
 *              friend functions
 */

/*
 *       class: auto_array
 *       brief: Template class of an array with automatic memory management.
 */

/*
 *    function: auto_array()
 *       brief: Default constructor
 *        post: Construct an auto_array object
 */

/*
 *    function: auto_array(const int)
 *       brief: Constructs an auto_array of input size
 *        post:
 *       param: size
 */

/*
 *    function: auto_array(const int, const T&)
 *       brief: Size and value constructor
 *        post: Constructs an auto_array of input size with all cells of input
 *              value.
 *       param: size
 *       param: value
 */

/*
 *    function: auto_array(const auto_array<T>&)
 *       brief: Copy constructor
 *        post: Constructs an auto_array object with same values
 *              found in input.
 *       param: auto_array object to be copied into new auto_array
 */

/*
 *    function: auto_array(auto_array<T>&&)
 *       brief: Move constructor
 *        post: Moves memory for a new auto_array object from input.
 *       param: auto_array object to be moved into new auto_array
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

    auto_array();
    auto_array(const int size);
    auto_array(const int size, const T& value);
    auto_array(const auto_array<T>& src);
    auto_array(auto_array<T> &&other);
    ~auto_array();

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
    auto_array<T>& operator=(auto_array<T> &&other);
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
