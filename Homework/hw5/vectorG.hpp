/* ************************************************************************** *\
 * vectorG.hpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */


template <class Ele_T>
void oonm::swap(oonm::Vector<Ele_T> &v1, oonm::Vector<Ele_T> &v2)
{
  using std::swap;

  swap(v1.data_,v2.data_);
  swap(v1.size_, v2.size_);

  return;
}

template <class T>
oonm::Vector<T> oonm::operator * (const T& C, const oonm::Vector<T>& v2)
{
  return v2*C;
}

template <class T>
oonm::Vector<T> oonm::operator + (const oonm::Vector<T>& v1,
                                  const oonm::Vector<T>& v2)
{
  oonm::Vector<T> ret(v1);

  return ret += v2;
}

template <class T>
oonm::Vector<T> oonm::operator - (const oonm::Vector<T>& v1,
                            const oonm::Vector<T>& v2)
{
  oonm::Vector<T> ret(v1);

  return ret-=v2;
}

template <class T>
oonm::Vector<T> oonm::operator - (const oonm::Vector<T>& vec)
{
  oonm::Vector<T> ret(vec);
  size_t it=-1;
  for(auto& val: vec)
    ret[++it] = -val;

  return ret;
}

template <class T>
bool oonm::operator == (const oonm::Vector<T>& lhs,
                  const oonm::Vector<T>& rhs)
{
  size_t i = 0;
  if(lhs.size_ == rhs.size_)
  {
    while(i < lhs.size_ && rhs.data_[i] == lhs.data_[i])
    {
      ++i;
    }
  }

  return (i==rhs.size_ && i==lhs.size_)?true:false;
}

template <class T>
bool oonm::operator != (const oonm::Vector<T>& lhs, const oonm::Vector<T>& rhs)
{
    return !(lhs==rhs);
}

template <class T>
std::ostream& oonm::operator<<(std::ostream& out, const oonm::Vector<T>& vec)
{
  for(size_t i=0; i<vec.size_; ++i)
  {
    out << std::scientific
        << std::setprecision(4)
        << std::setw(12)
        << std::left
        << std::setfill(' ')
        << vec[i];
    out << '\n';
  }
  return out;
}

template <class T>
std::istream& oonm::operator>>(std::istream& in, oonm::Vector<T>& vec)
{
  for(size_t i=0; i<vec.size_ && !in.eof(); ++i)
  {
    in >> vec[i];
  }

  if(in.eof())
    throw oonm::FatalError("Vector: operator >>: Invalid input format!");

  return in;
}

template <class T>
oonm::Vector<T> oonm::cat(const oonm::Vector<T>& a1, const oonm::Vector<T>& a2)
{
  oonm::Vector<T> ret(a1.get_size() + a2.get_size());
  int i=-1;
  for(auto& val: a1)
    ret[++i] = val;

  for(auto& val: a2)
    ret[++i] = val;

   return ret;
}

template <class T>
T oonm::sum(const oonm::Vector<T>& vec)
{
  return vec.sum();
}

template <class T>
oonm::Vector<T> sqrt(const oonm::Vector<T>& vec)
{
  oonm::Vector<T> ret(vec.get_size());
  size_t it = 0;

  for(auto& val: vec)
  {
    ret[it++] = sqrt(val);
  }

  return ret;
}

template <class T>
oonm::Vector<T> abs(const oonm::Vector<T>& vec)
{
  oonm::Vector<T> ret(vec.get_size());
  size_t it = 0;

  for(auto& val: vec)
  {
    ret[it++] = abs(val);
  }

  return ret;
}
