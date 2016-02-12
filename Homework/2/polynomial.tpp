/*
 * autoArray.tpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Implementation of polynomial template class and associated
 *              friend functions
 */

template <class T>
polynomial_fnct<T>::polynomial_fnct()
{
  m_data.set_size(0);
}

template <class T>
polynomial_fnct<T>::polynomial_fnct(const T& coeff, const T& order)
{
  m_data.set_size(1);
  m_data[0].m_coeff = coeff;
  m_data[0].m_order = order;
}

template <class T>
polynomial_fnct<T>& polynomial_fnct<T>::operator =
    (const polynomial_fnct<T>& src)
{
  if(this != &src)
  {
    m_data = src.m_data;
  }

  return *this;
}

template <class T>
polynomial_fnct<T>::polynomial_fnct
    (const polynomial_fnct<T>& src)
{
  *this = src;
}

template <class T>
polynomial_fnct<T>& polynomial_fnct<T>::operator =
    (polynomial_fnct<T>&& other)
{
  if(this != &other)
  {
    m_data = std::move(other.m_data);
  }

  return *this;
}

template <class T>
polynomial_fnct<T>::polynomial_fnct
    (polynomial_fnct<T>&& other)
{
  *this = std::move(other);
}

template <class T>
polynomial_fnct<T>::~polynomial_fnct()
{}

// Operator Overloads

template <class T>
const polynomial_fnct<T>& polynomial_fnct<T>::operator+=
    (const polynomial_fnct<T>& rhs)
{
  auto_array<term> cat(rhs.get_nterms() + get_nterms());

  for(int i=0; i < rhs.get_nterms(); ++i)
  {
    cat[i] = rhs.m_data[i];
  }

  for(int i=rhs.get_nterms(); i < cat.get_size(); ++i)
  {
    cat[i] = m_data[i-rhs.get_nterms()];
  }

  cat.sort();

  m_data = cat;

  simplify();

  return *this;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator+
    (const polynomial_fnct<T>& rhs) const
{
  polynomial_fnct<T> ret(*this);

  ret += rhs;

  return ret;
}

template <class T>
const polynomial_fnct<T>& polynomial_fnct<T>::operator-=
    (const polynomial_fnct<T>& rhs)
{
  auto_array<term> cat(rhs.get_nterms() + get_nterms());

  for(int i=0; i < rhs.get_nterms(); ++i)
  {
    cat[i].m_coeff  -rhs.m_data[i].m_coeff;
    cat[i].m_order = rhs.m_data[i].m_order;
  }

  for(int i=rhs.get_nterms(); i < cat.get_size(); ++i)
  {
    cat[i].m_coeff  -rhs.m_data[i-rhs.get_nterms()].m_coeff;
    cat[i].m_order = rhs.m_data[i-rhs.get_nterms()].m_order;
  }

  cat.sort();

  m_data = cat;

  simplify();

  return *this;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator-
    (const polynomial_fnct<T>& rhs) const
{
  polynomial_fnct<T> ret(*this);

  ret -= rhs;

  return ret;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator-() const
{
  polynomial_fnct<T> ret(*this);

  for(int i=0; i<get_nterms(); ++i)
    ret.m_data[i].m_coeff = -m_data[i].m_coeff;

  return ret;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator~() const
{
  polynomial_fnct<T> ret(*this);
  for(int i=0; i<get_nterms(); ++i)
  {
    if(m_data[i].m_coeff > 0)
    {
      ret.m_data[i].m_coeff = -m_data[i].m_coeff;
    }
  }

  return ret;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator[]
    (const int i) const
{
  polynomial_fnct<T> p(m_data[i].m_coeff, m_data[i].m_order);
  return p;
}

template <class T>
T polynomial_fnct<T>::operator()
    (const T& x) const
{
  T value=0;
  for(int i=0; i < get_nterms(); ++i)
  {
    value += m_data[i](x);
  }
  return value;
}

// Friends

template <class T>
bool operator==
    ( const polynomial_fnct<T>& lhs, const polynomial_fnct<T>& rhs)
{
  bool isEqual = true;
  if(&lhs != &rhs)
  {
    isEqual = (lhs.get_nterms()==rhs.get_nterms());
    if(isEqual)
    {
      isEqual = (lhs.m_data == rhs.m_data);
    }
  }
  else
  {
    isEqual = true;
  }

  return isEqual;
}

template <class T>
bool operator!=
    (const polynomial_fnct<T>& lhs, const polynomial_fnct<T>& rhs)
{
  return !(lhs == rhs);
}

template <class T>
std::ostream& operator<<
    (std::ostream& out, const polynomial_fnct<T>& p)
{
  T c, o;
  if(p.get_nterms()<=0)
  {
    out << '0';
  }
  else
  {
    for(int i=0; i < p.m_data.get_size(); ++i)
    {

      c = p.m_data[i].m_coeff;
      o = p.m_data[i].m_order;
      if(p.m_data[i].m_coeff != 0)
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
    }
  }
  return out;
}

template <class T>
std::istream& operator>>
    (std::istream& in, polynomial_fnct<T>& p)
{
    int input_terms, nterms;
    T tmpT;
    char* dummy = new char[256];

    nterms = 0;
    in >> input_terms;
    p.m_data.set_size(input_terms);

    for(int j=0;j < input_terms; ++j)
    {
      // Check if there are no more inputs
      if(in.get() == '\n') break;
      in.unget();

      in >> p.m_data[j].m_coeff;

      if(in.get() == '\n')
      {
        throw std::invalid_argument("read term: pair not found\n");
      }
      in.unget();

      in >> p.m_data[j].m_order;
      ++nterms;
    }

    if(in.get() != '\n')
      in.ignore(256, '\n');

    if(nterms < input_terms)
      p.m_data.resize(nterms);

    p.m_data.sort();

    p.simplify();
    delete[] dummy;
    return in;
}

template <class T>
void polynomial_fnct<T>::simplify()
{
  T tmpT;
  m_data.sort();

  for(int i=0; i<get_nterms()-1; ++i)
  {
    if(m_data[i].m_order == m_data[i+1].m_order)
    {
      tmpT = m_data[i].m_coeff + m_data[i+1].m_coeff;
      m_data[i+1].m_coeff = tmpT;
      m_data[i].m_coeff = 0;
    }
  }

  for(int i=0; i < m_data.get_size(); ++i)
  {
    if(m_data[i].m_coeff == 0)
    {
      m_data.remove(i);
      --i;
    }
  }

  return;
}

template <class T>
double polynomial_fnct<T>::magnitude() const
{
  double mag = 0;
  for(int i=0; i<get_nterms(); ++i)
    mag+=(m_data[i].m_coeff*m_data[i].m_coeff);

  mag = sqrt(mag);

  return mag;
}
