/*
 * autoArray.tpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Declarations of auto_array template class and associated
 *              friend functions
 */

template <class T>
vector<T>::vector()
{
  m_size = 0;
  m_max = 0;
  m_data.reset(nullptr);
}

template <class T>
vector<T>::vector(const int size)
{
  m_data.reset(new T[size]);
  m_size = size;
  m_max=size;
}

template <class T>
vector<T>::vector(const int size, const T& value)
{
  m_data.reset(new T[size]);
  m_size = size;
  m_max=size;
  for(int i=0; i < m_size; ++i)
  {
    m_data[i] = value;
  }
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& src)
{
  if(this != &src)
  {
    m_size = src.m_size;
    m_max = src.m_max;

    m_data.reset(new T[m_size]);

    for(int i = 0; i < m_size; ++i)
    {
      m_data[i] = src.m_data[i];
    }
  }

  return *this;
}

template <class T>
vector<T>::vector(const vector<T>& src)
{
  *this = src;
}

template <class T>
vector<T>& vector<T>::operator=(vector<T> &&other)
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
vector<T>::vector(vector<T> &&other)
{
  *this = std::move(other);
}

template <class T>
vector<T>::~vector()
{
}

template <class T>
void vector<T>::resize(const int size)
{
  std::unique_ptr<T[]> tmp;
  int nit = (size > m_size?m_size:size);
  if(m_data != nullptr && m_size > 0 && size > 0)
  {
    tmp.reset(new T[m_size]);
    for(int i=0; i < m_size; ++i)
    {
      tmp[i] = m_data[i];
    }
  }
  m_data.reset(new T[size]);
  if(tmp != nullptr)
  {
    for(int i=0; i < nit; ++i)
    {
      m_data[i] = tmp[i];
    }
  }
  m_size = size;
  m_max = size;

  return;
}

template <class T>
void vector<T>::reuse(const int size)
{
  if(size=0)
  {
    m_data.reset(nullptr);
    m_size = 0;
    m_max = 0;
  }
  else
  {
    this -> reuse();
    this -> resize(size);
  }
    return;
}

template <class T>
void vector<T>::set_size(const int size)
{
  this->resize(size);
}

template <class T>
void vector<T>::remove(const int i)
{
  if(i < m_size && m_size > 0 && i >=0)
  {
    for(int j = i; j < m_size - 1; ++j)
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
vector<T>& cat(const vector<T>& a1, const vector<T>& a2)
{

}

template <class T>
const T& vector<T>::operator[](const int i) const
{
  if(i > m_size || i < 0)
  {
    throw std::range_error("auto_array: subscript []: "\
        "index 'i' is out of range");
  }

  return m_data[i];
}

template <class T>
T& vector<T>::operator[](const int i)
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
void vector<T>::sort()
{
  if(!std::is_sorted(m_data.get(), m_data.get()+m_size))
    std::sort(m_data.get(), m_data.get()+m_size);
  //else
    //std::cout << "No need to sort!\n";

  return;
}

template <class T>
bool operator == (const vector<T>& lhs, const vector<T>& rhs)
{
  int i = 0;
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
bool operator != (const vector<T>& lhs, const vector<T>& rhs)
{
    return !(lhs==rhs);
}
