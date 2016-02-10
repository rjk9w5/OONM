//////////////////////////////////////////////////////////////////////
/// @file polynomial.tpp
/// @author Ryan J. Krattiger (rjk9w5) 
/// @brief Implementation of polynomial functions
//////////////////////////////////////////////////////////////////////

template <class T>
polynomial_fnct<T>::polynomial_fnct()
{
  m_data.set_size(0);
}

template <class T>
polynomial_fnct<T>& polynomial_fnct<T>::operator =(const polynomial_fnct<T>& src)
{
  if(this != &src)
  {
    m_data = src.m_data;
  }

  return *this;
}

template <class T>
polynomial_fnct<T>::polynomial_fnct(const polynomial_fnct<T>& src)
{
  *this = src;
}

template <class T>
polynomial_fnct<T>::~polynomial_fnct()
{}

//template <class T>
//Polynomial<T>::iterator Polynomial<T>::begin() const
//{
//  return m_data.begin();
//}
//
//template <class T>
//Polynomial<T>::iterator Polynomial<T>::end() const
//{
//  return m_data.end();
//}


// Operator Overloads

template <class T>
const polynomial_fnct<T>& polynomial_fnct<T>::operator+=(const polynomial_fnct<T>& rhs)
{
  auto_array<monomial<T>> cat(rhs.get_nterms() + get_nterms());

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
const polynomial_fnct<T> polynomial_fnct<T>::operator+(const polynomial_fnct<T>& rhs) const
{
  polynomial_fnct<T> ret(*this);

  ret += rhs;

  return ret;
}

template <class T>
const polynomial_fnct<T>& polynomial_fnct<T>::operator-=(const polynomial_fnct<T>& rhs)
{
  auto_array<monomial<T>> cat(rhs.get_nterms() + get_nterms());

  for(int i=0; i < rhs.get_nterms(); ++i)
  {
    cat[i].set_coeff(-rhs.m_data[i].get_coeff());
    cat[i].set_order(rhs.m_data[i].get_order());
  }

  for(int i=rhs.get_nterms(); i < cat.get_size(); ++i)
  {
    cat[i].set_coeff(m_data[i-rhs.get_nterms()].get_coeff());
    cat[i].set_order(m_data[i-rhs.get_nterms()].get_order());
  }

  cat.sort();

  m_data = cat;

  simplify();

  return *this;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator-(
    const polynomial_fnct<T>& rhs) const
{
  polynomial_fnct<T> ret(*this);
  // TODO addition
  ret -= rhs;

  return ret;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator-() const
{
  polynomial_fnct<T> ret(*this);

  for(int i=0; i<get_nterms(); ++i)
    ret.m_data[i].set_coeff(-m_data[i].get_coeff());

  return ret;
}

template <class T>
const polynomial_fnct<T> polynomial_fnct<T>::operator~() const
{
  polynomial_fnct<T> ret(*this);
  for(int i=0; i<get_nterms(); ++i)
  {
    if(m_data[i].get_coeff() > 0)
    {
      ret.m_data[i].set_coeff(-m_data[i].get_coeff());
    }
  }

  return ret;
}

template <class T>
monomial<T>& polynomial_fnct<T>::operator[](const int i)
{
  return m_data[i];
}

template <class T>
const monomial<T>& polynomial_fnct<T>::operator[](const int i) const
{
  return m_data[i];
}

template <class T>
T polynomial_fnct<T>::operator()(const T x) const
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
bool operator==(
    const polynomial_fnct<T>& lhs,
    const polynomial_fnct<T>& rhs)
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
    isEqual = false;
  }

  return isEqual;
}

template <class T>
bool operator!=(
    const polynomial_fnct<T>& lhs,
    const polynomial_fnct<T>& rhs)
{
  return !(lhs == rhs);
}

template <class T>
std::ostream& operator<<(
    std::ostream& out,
    const polynomial_fnct<T>& p)
{
  if(p.get_nterms()<=0)
  {
    out << '0';
  }
  else
  {
    for(int i=0; i < p.m_data.get_size(); ++i)
    {
      //std::cout << "Printing Polynomial\n";
      out << p.m_data[i];
    }
  }
  return out;
}

template <class T>
std::istream& operator>>(
    std::istream& in,
    polynomial_fnct<T>& p)
{
    int input_terms, nterms;
    monomial<T> mono;
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

      in >> mono;
      p.m_data[j] = mono;
      ++nterms;
    }

    if(in.get() != '\n')
      in.ignore(256, '\n');

    if(nterms < input_terms)
      p.m_data.resize(nterms);

    p.m_data.sort();

    p.simplify();

    return in;
}

template <class T>
void polynomial_fnct<T>::simplify()
{
  T tmpT;

  for(int i=0; i<get_nterms()-1; ++i)
  {
    if(m_data[i].get_order() == m_data[i+1].get_order())
    {
      tmpT = m_data[i].get_coeff() + m_data[i+1].get_coeff();
      m_data[i+1].set_coeff(tmpT);
      m_data[i].set_coeff(0);
    }
  }

  for(int i=0; i < m_data.get_size(); ++i)
  {
    if(m_data[i].get_coeff() == 0)
    {
      m_data.remove(i);
      --i;
    }
  }

  return;
}
