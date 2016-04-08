/* ************************************************************************** *\
 * matrix_tridiagI.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */

template <class Ele_T>
oonm::MatrixTriDiag<Ele_T>::MatrixTriDiag(
    std::size_t const n):
    data_(3*n - 2), n_(n)
{
}

template <class Ele_T>
oonm::MatrixTriDiag<Ele_T>::MatrixTriDiag(
    Vector<Ele_T> const &vneg1,
    Vector<Ele_T> const &v0,
    Vector<Ele_T> const &v1):
    data_(3*v0.get_size() - 2), n_(v0.get_size())
{
  this -> operator()(0,0) = v0[0];
  this -> operator()(0,1) = v1[0];
  this -> operator()(n_-1,n_-2) = *(vneg1.end());
  this -> operator()(n_-1,n_-1) = *(v0.end());
  for(std::size_t i=1; i<n_-1; ++i)
  {
    this -> operator()(i,i-1) = vneg1[i-1];
    this -> operator()(i,i) = v0[i];
    this -> operator()(i,i+1) = v1[i];
  }
}

template <class Ele_T>
oonm::MatrixTriDiag<Ele_T>::MatrixTriDiag(
    MatrixTriDiag<Ele_T> const &src):
    data_(src.data_),
    n_(src.n_)
{
}

template <class Ele_T>
oonm::MatrixTriDiag<Ele_T>::MatrixTriDiag(
    MatrixTriDiag<Ele_T> &&other):
    data_(std::move(other.data_)),
    n_(other.n_)
{
}

template <class Ele_T>
oonm::MatrixTriDiag<Ele_T>&
oonm::MatrixTriDiag<Ele_T>::operator = (
    MatrixTriDiag<Ele_T> src)
{
  swap(*this,src);

  return *this;
}

template <class Ele_T>
oonm::MatrixTriDiag<Ele_T>&
oonm::MatrixTriDiag<Ele_T>::operator = (
    std::shared_ptr<oonm::Matrix_type<Ele_T>> const src)
{
  n_ = src -> N();

  data_.set_size(3*n_ - 2);

  data_[0] = src -> operator()(0,0);
  data_[1] = src -> operator()(0,1);

  data_[3*(n_-1) - 1] = src -> operator()(n_-1,n_-2);
  data_[3*(n_-1)] = src -> operator()(n_-1,n_-1);

  for(std::size_t i=1; i<n_-1; ++i)
  {
    for(std::size_t j=i-1; j<=i+1; ++j)
    {
      data_[i*3 + static_cast<int>(j-i)] = src -> operator()(i,j);
    }
  }

  return *this;
}

template <class Ele_T>
inline Ele_T&
oonm::MatrixTriDiag<Ele_T>::operator ()(
    std::size_t const i,
    std::size_t const j)
{
#ifdef DEBUGFULL
  if(!(checki(i) && checkj(j))) throw RangeException("TDMat op()");
#endif

  if(abs(static_cast<int>(j-i)) <= 1)
    return data_[i*3 + static_cast<int>(j-i)];

  if(vempty != 0) vempty = 0;

  return vempty;
}

template <class Ele_T>
inline Ele_T const &
oonm::MatrixTriDiag<Ele_T>::operator ()(
    std::size_t const i,
    std::size_t const j) const
{
#ifdef DEBUGFULL
  if(!(checki(i) && checkj(j))) throw RangeException("TDMat op() const");
#endif
  if(abs(static_cast<int>(j-i)) <= 1)
    return data_[i*3 + static_cast<int>(j-i)];

  return cempty;
}

template <class Ele_T>
inline std::shared_ptr<oonm::Matrix_type<Ele_T>>
oonm::MatrixTriDiag<Ele_T>::clone() const
{
  return std::shared_ptr<oonm::Matrix_type<Ele_T>>(
      new oonm::MatrixTriDiag<Ele_T>(*this));
}

template <class Ele_T>
inline bool
oonm::MatrixTriDiag<Ele_T>::checki(
    std::size_t const i) const
{
  return (n_)&&(i<n_);
}

template <class Ele_T>
inline bool
oonm::MatrixTriDiag<Ele_T>::checkj(
    std::size_t const j) const
{
  return (n_)&&(j<n_);
}

template <class Ele_T>
inline std::size_t
oonm::MatrixTriDiag<Ele_T>::N() const
{
  return n_;
}

template <class Ele_T>
inline std::size_t
oonm::MatrixTriDiag<Ele_T>::M() const
{
  return n_;
}

template <class Ele_T>
void
oonm::MatrixTriDiag<Ele_T>::swapr(
    std::size_t const r1,
    std::size_t const r2)
{
  std::cerr << "Warning: Tridiagonal not functional for swapr(r1,r2)\n";
  return;
}

template <class Ele_T>
void
oonm::MatrixTriDiag<Ele_T>::swapc(
    std::size_t const c1,
    std::size_t const c2)
{
  std::cerr << "Warning: Tridiagonal not functional for swapc(c1,c2)\n";
  return;
}

template <class Ele_T>
inline void
oonm::MatrixTriDiag<Ele_T>::set_size(
    std::size_t const n,
    std::size_t const m)
{
  n_ = n;
  data_.set_size(n_*3-2);

  return;
}

template <class Ele_T>
inline void
oonm::MatrixTriDiag<Ele_T>::set_size(
    std::size_t const n)
{
  n_ = n;
  data_.set_size(n_*3-2);

  return;
}

template <class Ele_T>
void
oonm::MatrixTriDiag<Ele_T>::print(
    std::ostream& out) const
{
  out << '(' << 0 << ',' << 0 << ')' << ' ';
  out << std::left << std::setw(7) << std::setprecision(3)
      << this -> operator()(0,0) << '\n';
  for(std::size_t i=1; i<n_-1; ++i)
  {
    for(std::size_t j=i-1; j<=i+1; ++j)
    {
      out << '(' << i << ',' << j << ')' << ' ';
      out << std::left << std::setw(7) << std::setprecision(3)
          << this -> operator()(i,j) << '\n';
    }
  }
  out << '(' << n_-1 << ',' << n_-1 << ')' << ' ';
  out << std::left << std::setw(7) << std::setprecision(3)
      << this -> operator()(n_-1,n_-1) << '\n';

  return;
}
