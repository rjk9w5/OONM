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
    data_(n*m), n_(n), m_(m)
{
}

template <class Ele_T>
oonm::MatrixDense<Ele_T>::MatrixDense(
    MatrixDense<Ele_T> const &src):
    data_(src.data_),
    n_(src.n_), m_(src.m_)
{
}

template <class Ele_T>
oonm::MatrixDense<Ele_T>::MatrixDense(
    MatrixDense<Ele_T> &&other):
    data_(std::move(other.data_)),
    n_(other.n_),
    m_(other.m_)
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
  n_ = src -> N();
  m_ = src -> M();

  data_.set_size(n_*m_);

  for(std::size_t i=0; i<n_; ++i)
  {
    for(std::size_t j=0; j<m_; ++j)
    {
      data_[i*m_ + j] = src -> operator()(i,j);
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
  return data_[i*m_ + j];
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
  return data_[i*m_ + j];
}

template <class Ele_T>
inline std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::MatrixDense<Ele_T>::clone() const
{
  return std::shared_ptr<oonm::Matrix_type<Ele_T>>(
      new oonm::MatrixDense<Ele_T>(*this));
}

template <class Ele_T>
inline bool
oonm::MatrixDense<Ele_T>::checki(
    std::size_t const i) const
{
  return (n_)&&(i<n_);
}

template <class Ele_T>
inline bool
oonm::MatrixDense<Ele_T>::checkj(
    std::size_t const j) const
{
  return (m_)&&(j<m_);
}

template <class Ele_T>
inline std::size_t
oonm::MatrixDense<Ele_T>::N() const
{
  return n_;
}

template <class Ele_T>
inline std::size_t
oonm::MatrixDense<Ele_T>::M() const
{
  return m_;
}

template <class Ele_T>
inline void
oonm::MatrixDense<Ele_T>::set_size(
    std::size_t const n,
    std::size_t const m)
{
  n_ = n;
  m_ = m;
  data_.set_size(n_*m_);
  return;
}

template <class Ele_T>
void
oonm::MatrixDense<Ele_T>::print(
    std::ostream& out) const
{
  for(std::size_t i=0; i<n_; ++i)
  {
    for(std::size_t j=0; j<m_; ++j)
    {
      out << std::left << std::setw(7) << std::setprecision(3)
          << this -> operator()(i,j) << ' ';
    }
    out << '\n';
  }
}


template <class Ele_T>
void
oonm::swap(
    MatrixDense<Ele_T> &m1,
    MatrixDense<Ele_T> &m2)
{
  using std::swap;

  swap(m1.data_,m2.data_);
  swap(m1.n_,m2.n_);
  swap(m1.m_,m2.m_);

  return;
}

