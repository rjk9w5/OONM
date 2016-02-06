//////////////////////////////////////////////////////////////////////
/// @file polynomial.tpp
/// @author Ryan J. Krattiger (rjk9w5) 
/// @brief Implementation of polynomial functions
//////////////////////////////////////////////////////////////////////

template <class T>
Polynomial<T>::Polynomial()
{
  m_data.setSize(0);
  m_nterms = 0;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator =(const Polynomial<T>& src)
{
  if(this != &src)
  {
    this->m_nterms = src.m_nterms;
    this->m_data = src.m_data;
  }

  return *this;
}

template <class T>
Polynomial<T>::Polynomial(const Polynomial<T>& src)
{
  *this = src;
}

template <class T>
Polynomial<T>::~Polynomial()
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
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T>& rhs)
{
  *this = *this + rhs;

  return *this;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator+(const Polynomial<T>& rhs) const
{
  Polynomial<T> tmp;
  // TODO addition

  return tmp;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial<T>& rhs)
{
  *this = *this - rhs;

  return *this;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator-(const Polynomial<T>& rhs) const
{
  // TODO: Subtraction
}

template <class T>
Polynomial<T>& Polynomial<T>::operator-() const
{
  // TODO Unary minus

  return *this;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator~() const
{
  // TODO negation
  return *this;
}

template <class T>
bool Polynomial<T>::operator==(
    const Polynomial<T>& rhs) const
{
  bool isEqual = true;
  if(this != &rhs)
  {
    isEqual = (m_nterms==rhs.m_nterms);
    if(isEqual)
    {
      isEqual = (m_data == rhs.m_data);
    }
  }
  else
  {
    isEqual = true;
  }

  return isEqual;
}

template <class T>
bool Polynomial<T>::operator!=(const Polynomial<T>& rhs) const
{
  return !(*this == rhs);
}

template <class T>
monomial<T>& Polynomial<T>::operator[](const int i)
{
  // TODO: [] Write
  return *this;
}

template <class T>
const monomial<T>& Polynomial<T>::operator[](const int i) const
{
  // TODO: [] Read
  return *this;
}

template <class T>
double Polynomial<T>::operator()(const double x) const
{
  T value=0;
  for(int i=0; i < m_nterms; ++i)
  {
    value += m_data[i](x);
  }
  return value;
}

// Friends

template <class T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& p)
{
  for(int i=0; i < p.m_nterms; ++i)
  {
    out << p.m_data[i];
  }
}

template <class T>
std::istream& operator>>(std::istream& in, Polynomial<T>& p)
{
    int input_terms;
    monomial<T> mono;

    p.m_nterms = 0;
    in >> input_terms;
    p.m_data.setSize(input_terms);

    for(int j=0;j < input_terms; ++j)
    {
      // Check if there are no more inputs
      if(in.get() == '\n') break;
      in.unget();

//      // Get next term coefficient
//      in >> p.m_data[j].m_coeff;
//
//      if(in.get() == '\n') throw file_error("Incorrect input format.");
//      in.unget();
//
//      in >> p.m_data[j].m_order;
      in >> mono;
      p.m_data[j] = mono;
      ++p.m_nterms;
    }

    if(p.m_nterms < input_terms)
      p.m_data.resize(p.m_nterms);

    p.m_data.sort();

    return in;
}
