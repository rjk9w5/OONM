/*
 * matrix_denseI.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */


template <class Ele_T>
oonm::MatrixDense<Ele_T>::MatrixDense(
    std::size_t const n,
    std::size_t const m):
    data_(n*m), r_(n), c_(m)
{
}

template <class Ele_T>
oonm::MatrixDense<Ele_T>::MatrixDense(
    MatrixDense<Ele_T> const &src):
    data_(src.data_),
    r_(src.r_), c_(src.c_)
{
}

template <class Ele_T>
oonm::MatrixDense<Ele_T>::MatrixDense(
    MatrixDense<Ele_T> &&other):
    data_(std::move(other.data_)),
    r_(other.r_),
    c_(other.c_)
{
}

template <class Ele_T>
oonm::MatrixDense<Ele_T>&
oonm::MatrixDense<Ele_T>::operator = (
    MatrixDense<Ele_T> src)
{
  swap(*this,src);

  return *this;
}

template <class Ele_T>
oonm::MatrixDense<Ele_T>&
oonm::MatrixDense<Ele_T>::operator = (
    std::shared_ptr<oonm::Matrix_type<Ele_T>> const src)
{
  r_ = src -> get_nrows();
  c_ = src -> get_ncols();

  data_.set_size(r_*c_);

  for(std::size_t i=0; i<r_; ++i)
  {
    for(std::size_t j=0; j<c_; ++j)
    {
      data_[i*c_ + j] = src -> operator()(i,j);
    }
  }

  return *this;
}

template <class Ele_T>
inline Ele_T&
oonm::MatrixDense<Ele_T>::operator ()(
    std::size_t const i,
    std::size_t const j)
{
#ifdef DEBUGFULL
  if(!(checki(i) && checkj(j))) throw RangeException();
#endif
  return data_[i*c_ + j];
}

template <class Ele_T>
inline Ele_T const &
oonm::MatrixDense<Ele_T>::operator ()(
    std::size_t const i,
    std::size_t const j) const
{
#ifdef DEBUGFULL
  if(!(checki(i) && checkj(j))) throw RangeException();
#endif
  return data_[i*c_ + j];
}

template <class Ele_T>
inline std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::MatrixDense<Ele_T>::clone() const
{
  return std::shared_ptr<oonm::Matrix_type<Ele_T>>(new oonm::MatrixDense<Ele_T>(*this));
}

template <class Ele_T>
inline bool
oonm::MatrixDense<Ele_T>::checki(
    std::size_t const i) const
{
  return (r_)&&(i<r_);
}

template <class Ele_T>
inline bool
oonm::MatrixDense<Ele_T>::checkj(
    std::size_t const j) const
{
  return (c_)&&(j<c_);
}

template <class Ele_T>
inline std::size_t
oonm::MatrixDense<Ele_T>::get_nrows() const
{
  return r_;
}

template <class Ele_T>
inline std::size_t
oonm::MatrixDense<Ele_T>::get_ncols() const
{
  return c_;
}

template <class Ele_T>
inline void
oonm::MatrixDense<Ele_T>::set_size(
    std::size_t const n,
    std::size_t const m)
{
  r_ = n;
  c_ = m;
  data_.set_size(r_*c_);
  return c_;
}


template <class Ele_T>
void
oonm::swap(
    MatrixDense<Ele_T> &m1,
    MatrixDense<Ele_T> &m2)
{
  using std::swap;

  swap(m1.data_,m2.data_);
  swap(m1.r_,m2.r_);
  swap(m1.c_,m2.c_);

  return;
}

