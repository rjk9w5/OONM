/*
 * autoArray.tpp
 *
 *  Created on: Feb 5, 2016
 *      Author: ryan
 */

template <class T>
autoArray<T>::autoArray()
{
  m_size = 0;
  m_max = 0;
  m_data = nullptr;
}

template <class T>
autoArray<T>::autoArray(const int size)
{
  if(m_data != nullptr)
  {
    delete[] m_data;
  }
  m_data = new T[size];
  m_size = size;
  m_max=size;
}

template <class T>
autoArray<T>::autoArray(const int size, const T& value)
{
  if(m_data != nullptr)
  {
    delete[] m_data;
  }
  m_data = new T[size];
  m_size = size;
  m_max=size;
  for(int i=0; i < m_size; ++i)
  {
    m_data[i] = value;
  }
}

template <class T>
autoArray<T>& autoArray<T>::operator=(const autoArray<T>& src)
{
  if(this != &src)
  {
    m_size = src.m_size;
    m_max = src.m_max;
    if(m_data != nullptr)
    {
      delete[] m_data;
    }
    m_data = new T[m_max];
    for(int i = 0; i < m_size; ++i)
    {
      m_data[i] = src.m_data[i];
    }
  }
}

template <class T>
autoArray<T>::autoArray(const autoArray<T>& src)
{
  *this = src;
}

template <class T>
autoArray<T>::~autoArray()
{
  if(m_data != nullptr)
  {
    delete[] m_data;
  }
}

//template <class T>
//autoArray<T>::iterator autoArray<T>::end() const
//{
//  return m_data + m_size;
//}
//
//template <class T>
//autoArray<T>::iterator autoArray<T>::begin() const
//{
//  return m_data;
//}

template <class T>
void autoArray<T>::resize(const int size)
{
  T* tmp = nullptr;
  int nit = (size > m_size?m_size:size);
  if(m_data != nullptr && m_size > 0 && size > 0)
  {
    tmp = new T[m_size];
    for(int i=0; i < m_size; ++i)
    {
      tmp[i] = m_data[i];
    }
    delete[] m_data;
  }
  m_data = new T[size];
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
void autoArray<T>::reuse()
{
  if(m_data != nullptr)
  {
    delete[] m_data;
  }

  return;
}

template <class T>
void autoArray<T>::setSize(const int size)
{
  this->resize(size);
}

template <class T>
const T& autoArray<T>::operator[](const int i) const
{
  return *(m_data+i);
}

template <class T>
T& autoArray<T>::operator[](const int i)
{
  return *(m_data + i);
}

// Must have < operator implemented
template <class T>
void autoArray<T>::sort()
{
  std::sort(m_data, m_data+m_size);
}
