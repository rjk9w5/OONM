/*
 * monomial.tpp
 *
 *  Created on: Feb 11, 2016
 *      Author: ryan
 */


template <class T>
std::ostream& operator << (
    std::ostream& out,
    const monomial<T>& data)
{
  T c, o;
  c = data.m_coeff;
  o = data.m_order;
  if(data.m_coeff != 0)
  {
    if(o == 0)
    {
      if(c>0) out << '+' << ' ' << c;
      else out << '-' << ' ' << -c;
    }
    else if(o==1)
    {
      if(c==1 || c==-1)
      {
        out << (c>0?'+':'-') << ' ' << 'x';
      }
      else
      {
        out << (c>0?'+':'-') << ' ' << (c>0?c:-c) << '*' << 'x';
      }
    }
    else
    {
      if(c==1 || c==-1)
      {
        out << (c>0?'+':'-') << ' ' << 'x';
      }
      else
      {
        out << (c>0?'+':'-') << ' ' << (c>0?c:-c) << '*' << 'x';
      }
      out << '^' << o;
    }
    out << ' ';
  }

  return out;
}

template <class T>
std::istream& operator >>(
    std::istream& in,
    monomial<T>& data)
{
  // Get next term coefficient
  in >> data.m_coeff;

  if(in.get() == '\n')
  {
    throw std::invalid_argument("read monomial: pair not found\n");
  }
  in.unget();

  in >> data.m_order;

  return in;
}

template <class T>
bool operator ==(const monomial<T>& lhs, const monomial<T>& rhs)
{
    return (lhs.m_coeff == rhs.m_coeff && lhs.m_order == rhs.m_order);
}

template <class T>
bool operator !=(const monomial<T>& lhs, const monomial<T>& rhs)
{
    return !(lhs == rhs);
}

template <class T>
bool monomial<T>::operator < (const monomial<T>& cmp) const
{
  return m_order < cmp.m_order;
}

template <class T>
monomial<T>& monomial<T>::operator =(const monomial<T>& src)
{
  m_order = src.m_order;
  m_coeff = src.m_coeff;

  return *this;
}

template <class T>
const T monomial<T>::operator()(const T& x) const
{
  T ret;
  ret = m_coeff*pow(x,m_order);
  return ret;
}

