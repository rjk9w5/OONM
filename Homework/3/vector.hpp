/*
 * vector.hpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Declarations of vector template class and associated
 *              friend functions
 */

template <class T>
oonm::Vector<T>::Vector():
    m_size(0), m_max(0), m_data(nullptr)
{}

template <class T>
oonm::Vector<T>::Vector(const size_t size):
    m_size(size), m_max(size), m_data(new T[size])
{}

template <class T>
oonm::Vector<T>::Vector(const size_t size, const T& value):
    m_size(size), m_max(size), m_data(new T[size])
{
  for(size_t i=0; i < m_size; ++i)
  {
    m_data[i] = value;
  }
}

template <class T>
oonm::Vector<T>& oonm::Vector<T>::operator=(const oonm::Vector<T>& src)
{
  if(this != &src)
  {
    // TODO: Figure out how to make copy and swap technique work.
    //std::swap(*this,src);
    m_size = src.m_size;
    m_max = src.m_max;

    m_data.reset(new T[m_size]);

    for(size_t i = 0; i < m_size; ++i)
    {
      m_data[i] = src.m_data[i];
    }
  }

  return *this;
}

template <class T>
oonm::Vector<T>::Vector(const oonm::Vector<T>& src)
{
  *this = src;
}

template <class T>
oonm::Vector<T>& oonm::Vector<T>::operator=(oonm::Vector<T> &&other)
{
  if(this != &other)
  {
    m_size = other.m_size;
    m_max = other.m_max;

    m_data = std::move(other.m_data);
    other.m_data.reset(nullptr);
  }

  return *this;
}

template <class T>
oonm::Vector<T>::Vector(oonm::Vector<T> &&other)
{
  *this = std::move(other);
}

template <class T>
oonm::Vector<T>::~Vector()
{
}

template <class T>
void oonm::Vector<T>::resize(const size_t size)
{
  std::unique_ptr<T[]> tmp;
  size_t nit = (size > m_size?m_size:size);
  if(size < 0) std::exception();

  if(m_data != nullptr && m_size > 0 && size)
  {
    tmp.reset(new T[m_size]);
    for(size_t i=0; i < m_size; ++i)
    {
      tmp[i] = m_data[i];
    }
  }
  m_data.reset(new T[size]);
  if(tmp != nullptr)
  {
    for(size_t i=0; i < nit; ++i)
    {
      m_data[i] = tmp[i];
    }
  }
  m_size = size;
  m_max = size;

  return;
}

template <class T>
void oonm::Vector<T>::reuse(const size_t size)
{
  if(size > 0)
    m_data.reset(new T[size]);
  else
    m_data.reset(nullptr);

  m_size = size;
  m_max = size;
  return;
}

template <class T>
void oonm::Vector<T>::set_size(const size_t size)
{
  this->resize(size);
  return;
}

template <class T>
void oonm::Vector<T>::remove(const size_t i)
{
  if(i < m_size && m_size > 0 && i >=0)
  {
    for(size_t j = i; j < m_size - 1; ++j)
      m_data[j] = m_data[j+1];

    m_size--;
  }
  else
  {
    throw std::range_error("auto_array: remove: index 'i' is out of range\n");
  }

  return;
}

template <class T>
const T& oonm::Vector<T>::operator[](const size_t i) const
{
  if(i > m_size || i < 0)
  {
    throw std::range_error("auto_array: subscript []: "\
        "index 'i' is out of range");
  }

  return m_data[i];
}

template <class T>
T& oonm::Vector<T>::operator[](const size_t i)
{
  if(i > m_size || i < 0)
  {
    throw std::range_error("auto_array: subscript []: "\
        "index 'i' is out of range");
  }

  return m_data[i];
}

// Must have < operator implemented
template <class T>
oonm::Vector<T>& oonm::Vector<T>::sort()
{
  if(!std::is_sorted(m_data.get(), m_data.get()+m_size))
    std::sort(begin(), end());

  return *this;
}

template <class T>
T* oonm::Vector<T>::begin() const
{
  return m_data.get();
}

template <class T>
T* oonm::Vector<T>::end() const
{
  return m_data.get() + m_size;
}

template <class T>
oonm::Vector<T> oonm::Vector<T>::slice(const T* start, const T* stop, const size_t step) const
{
  size_t slice_size = m_size/step +
                      ((m_size%step||step>m_size)&&m_size!=step?1:0);

  if(slice_size <= 0) throw std::exception();

  oonm::Vector<T> ret(slice_size);
  size_t i=-1;
  const T* it = start;
  for(; it<stop; it+=step)
    ret[++i] = *it;

  return ret;
}

template <class T>
int oonm::Vector<T>::find(const T& value)
{
  size_t i_left=0;
  size_t i_right = m_size-1;
  size_t index = (i_right - i_left)/2;

  if(m_data[i_right] == value) return i_right;
  if(m_data[i_left] == value) return i_left;

  while(m_data[index] != value)
  {
    if(m_data[index] > value)
    {
      i_right = index;
      index = i_left + (i_right - i_left)/2;
    }
    else if(m_data[index] < value)
    {
          i_left = index;
          index = i_left + (i_right - i_left)/2;
    }

    if(i_left == index) return -1;
  }

  return index;
}

// MATH
template <class T>
T oonm::Vector<T>::dot(const oonm::Vector<T>& vec) const
{
  if(vec.get_size() != get_size()) throw std::exception();

  T ret;
  size_t it = -1;
  for(auto val: *this)
    ret += val*vec[++it];

  return ret;
}

template <class T>
T oonm::dot(const oonm::Vector<T>& v1, const oonm::Vector<T>& v2)
{
  return v1.dot(v2);
}

template <class T>
T oonm::Vector<T>::operator * (const oonm::Vector<T>& vec) const
{
  return dot(vec);
}

template <class T>
oonm::Vector<T> oonm::Vector<T>::operator * (const T& C) const
{
  oonm::Vector<T> ret(*this);
  size_t it=-1;
  for(auto val: *this)
    ret[++it] = val*C;

  return  ret;
}

template <class T>
oonm::Vector<T> oonm::Vector<T>::operator / (const oonm::Vector<T>& v2) const
{
  if(v2.get_size() != get_size()) throw std::exception();

  oonm::Vector<T> ret(*this);
  size_t it =0;
  for(auto val: v2)
  {
    ret[it++] /= val;
  }
  return ret;
}

template <class T>
oonm::Vector<T> oonm::Vector<T>::operator / (const T& C) const
{
  oonm::Vector<T> ret(*this);
  size_t it =0;
  for(auto val: ret)
  {
    ret[it++] /= C;
  }
  return ret;
}

template <class T>
oonm::Vector<T> oonm::operator * (const T& C, const oonm::Vector<T>& v2)
{
    return v2*C;
}

template <class T>
oonm::Vector<T>& oonm::Vector<T>::operator += (const oonm::Vector<T>& vec)
{
  if(vec.get_size() != get_size()) throw std::exception();

  size_t it=-1;
  for(auto val: vec)
    this -> operator[](++it) += val;

  return *this;
}

template <class T>
oonm::Vector<T> oonm::operator + (const oonm::Vector<T>& v1,
                            const oonm::Vector<T>& v2)
{
  oonm::Vector<T> ret(v1);
  ret+=v2;

  return ret;
}

template <class T>
oonm::Vector<T> oonm::operator - (const oonm::Vector<T>& v1,
                            const oonm::Vector<T>& v2)
{
  if(v1.get_size() != v2.get_size()) throw std::exception();

  oonm::Vector<T> ret(v1.get_size());
  size_t it=-1;
  for(auto val: v1)
    ret[++it] = val-v2[it];

  return ret;
}

template <class T>
oonm::Vector<T> oonm::operator - (const oonm::Vector<T>& vec)
{
  oonm::Vector<T> ret(vec);
  size_t it=-1;
  for(auto val: vec)
    ret[++it] = -val;

  return ret;
}

template <class T>
bool oonm::operator == (const oonm::Vector<T>& lhs,
                  const oonm::Vector<T>& rhs)
{
  size_t i = 0;
  if(lhs.m_size == rhs.m_size)
  {
    while(i < lhs.m_size && rhs.m_data[i] == lhs.m_data[i])
    {
      ++i;
    }
  }

  return (i==rhs.m_size && i==lhs.m_size)?true:false;
}

template <class T>
bool oonm::operator != (const oonm::Vector<T>& lhs, const oonm::Vector<T>& rhs)
{
    return !(lhs==rhs);
}

template <class T>
std::ostream& oonm::operator<<(std::ostream& out, const oonm::Vector<T>& vec)
{
  for(int i=0; i<vec.m_size; ++i)
  {
    out << std::setprecision(5)
        << std::setw(10)
        << std::left
        << std::setfill(' ')
        << vec[i];
  }
  out << '\n';
  return out;
}

template <class T>
std::istream& oonm::operator>>(std::istream& in, oonm::Vector<T>& vec)
{
  for(int i=0; i<vec.m_size; ++i)
  {
    in >> vec[i];
  }

  return in;
}

template <class T>
oonm::Vector<T> cat(const oonm::Vector<T>& a1, const oonm::Vector<T>& a2)
{
  oonm::Vector<T> ret(a1.get_size() + a2.get_size());
  int i=-1;
  for(auto val: a1)
    ret[++i] = val;

  for(auto val: a2)
    ret[++i] = val;

   return ret;
}

template <class T>
T oonm::Vector<T>::sum() const
{
  T sm=0;
  for(auto val: *this)
  {
    sm += val;
  }
  return sm;
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

  for(auto val: vec)
  {
    ret[it++] = sqrt(val);
  }

  return ret;
}
