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
 *       brief: Default constructor.
 *        post: Construct an auto_array object.
 */

/*
 *    function: auto_array(const int size)
 *       brief: Constructs an auto_array of input size.
 *        post: Constructs an auto_array of input size.
 *       param: size is an int type.
 */

/*
 *    function: auto_array(const int size, const T& value)
 *       brief: Size and value constructor.
 *        post: Constructs an auto_array of input size with all cells of input
 *              value.
 *       param: size is an int type.
 *       param: value is a T type.
 */

/*
 *    function: auto_array(const auto_array<T>& src)
 *       brief: Copy constructor
 *        post: Constructs an auto_array object with same values
 *              found in input.
 *       param: auto_array object to be copied into new auto_array.
 */

/*
 *    function: auto_array(auto_array<T>&& other)
 *       brief: Move constructor
 *        post: Moves memory for a new auto_array object from input.
 *       param: auto_array object to be moved into new auto_array.
 */

/*
 *    function: operator=(const auto_array<T>& src)
 *       brief: Copy assignment operator.
 *        post: Copies data from src to calling object.
 *       param: src is an auto_array type.
 *      return: calling object.
 */

/*
 *    function: operator=(auto_array<T>&& other)
 *       brief: Move assignment operator.
 *        post: Moves data from other to calling object.
 *       param: other is an auto_array type.
 *      return: calling object.
 */

/*
 *    function: ~auto_array()
 *       brief: Destructor
 *        post: Destroys auto_array object.
 */

/*
 *    function: resize(const int size)
 *       brief: Resizes auto_array while only destroying data in cells with
 *              indices greater than the new size.
 *        post: Resizes auto_array but saves data.
 *       param: size to resize to, default=0. (int)
 *      return: none
 */

/*
 *    function: reuse(const int size)
 *       brief: destroys all existing data and applies a new size.
 *        post: destroys all existing data and applies a new size.
 *       param: size to resize to, default=0. (int)
 *      return: none
 */

/*
 *    function: set_size(const int size)
 *       brief: destroys all existing data and sets new size.
 *        post: destroys all existing data and sets new size.
 *       param: size to resize to. (int)
 *      return: none
 */

/*
 *    function: get_size()
 *       brief: returns size.
 *        post: returns size.
 *      return: size of auto_array calling object. (int)
 */

/*
 *    function: remove(const int i)
 *       brief: removes value at index i if it exists.
 *        post: value at index i is removed and data is shifted.
 *       param: index i to be removed.
 *      return: none
 */

/*
 *    function: operator[](const int i) const
 *       brief: read only access element at index i
 *        post: returns element value at index i
 *       param: index i to be accessed
 *      return: returns element value at index i
 */

/*
 *    function: operator[](const int i)
 *       brief: read-write access element at index i
 *        post: returns element value at index i
 *       param: index i to be accessed
 *      return: returns element value at index i
 */

/*
 *    function: sort()
 *       brief: Sorts auto_array calling object
 *         pre: Requires template type T to have < operator implemented
 *        post: Sorts auto_array
 *      return: none
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

    void resize(const int size=0);

    void reuse(const int size=0);

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
