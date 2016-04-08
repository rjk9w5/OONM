/* ************************************************************************** *\
 * pair.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */
#ifndef PAIR_H_
#define PAIR_H_


namespace oonm
{

  template <class Key_T, class Value_T>
  class Pair;

  template <class Key_T, class Value_T>
  class Pair
  {
    public:
      Pair() = default;
      Pair(Key_T const &k, Value_T const &v);

      bool
      operator < (
          Key_T const &ref_key) const
      {
        return key_ < ref_key;
      }

      bool
      operator == (
          Key_T const &ref_key) const
      {
        return !(key_ < ref_key || ref_key < key_);
      }

      bool
      operator != (
          Key_T const &ref_key) const
      {
        return !(*this == ref_key);
      }

      bool
      operator <= (
          Key_T const &ref_key) const
      {
        return key_ < ref_key || *this == ref_key;
      }

      bool
      operator > (
          Key_T const &ref_key) const
      {
        return !(*this <= ref_key);
      }

      bool
      operator >= (
          Key_T const &ref_key) const
      {
        return !(*this < ref_key);
      }
// ------------------------------------------
      bool
      operator < (
          Pair const &ref_p) const
      {
        return ref_p > key_;
      }

      bool
      operator == (
          Pair const &ref_p) const
      {
        return !(key_ < ref_p || ref_p < key_);
      }

      bool
      operator != (
          Pair const &ref_p) const
      {
        return !(*this == ref_p);
      }

      bool
      operator <= (
          Pair const &ref_p) const
      {
        return key_ < ref_p || *this == ref_p;
      }

      bool
      operator > (
          Pair const &ref_p) const
      {
        return !(*this <= ref_p);
      }

      bool
      operator >= (
          Pair const &ref_p) const
      {
        return !(*this < ref_p);
      }

      Key_T const&
      key() const
      {
        return key_;
      }

      Key_T &
      key()
      {
        return key_;
      }

      void
      key(
          Key_T const &k)
      {
        key_ = k;
      }

      Value_T const &
      value() const
      {
        return value_;
      }

      Value_T &
      value()
      {
        return value_;
      }

      void
      value(
          Value_T const &v)
      {
        value_ = v;
      }

      operator Key_T()
      {
        return key_;
      };

      operator Value_T()
      {
        return value_;
      };

    private:
      Key_T key_;
      Value_T value_;
  };

  template <class Key_T, class Value_T>
  bool
  operator < (
      Key_T const &ref_key,
      Pair<Key_T, Value_T> const &p)
  {
    return p < ref_key;
  }

  template <class Key_T, class Value_T>
  bool
  operator > (
      Key_T const &ref_key,
      Pair<Key_T, Value_T> const &p)
  {
    return p > ref_key;
  }

}


#endif /* PAIR_H_ */
