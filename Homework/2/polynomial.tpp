//////////////////////////////////////////////////////////////////////
/// @file polynomial.tpp
/// @author Ryan J. Krattiger (rjk9w5) 
/// @brief Implementation of polynomial functions
//////////////////////////////////////////////////////////////////////

template <class T>
Polynomial<T>::Polynomial();

template <class T>
Polynomial<T>::Polynomial(const Polynomial<T>& src);

template <class T>
Polynomial<T>::~Polynomial()
{
    delete[] m_coeff;
    delete[] m_order;
}
// Operator Overloads

template <class T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T>& rhs);

template <class T>
Polynomial<T>& Polynomial<T>::operator+(const Polynomial<T>& rhs) const;

template <class T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial<T>& rhs);

template <class T>
Polynomial<T>& Polynomial<T>::operator-(const Polynomial<T>& rhs) const;

template <class T>
Polynomial<T>& Polynomial<T>::operator-() const;

template <class T>
Polynomial<T>& Polynomial<T>::operator~() const;

template <class T>
bool Polynomial<T>::operator==(const Polynomial<T>& rhs, const Polynomial<T>& lhs) const;

template <class T>
bool Polynomial<T>::operator!=(const Polynomial<T>& rhs, const Polynomial<T>& lhs) const;

template <class T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial<T>& rhs);

template <class T>
T& Polynomial<T>::operator[](const int i);

template <class T>
const T& Polynomial<T>::operator[](const int i) const;

template <class T>
T& Polynomial<T>::operator()(const T& x) const;

// Friends

template <class T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& p);

template <class T>
std::istream& operator>>(std::istream& in, Polynomial<T>& p)
{
    int nRow;

    in >> nRow;
    for(int j=0;j < nRow; ++j)
    {
      if(in.get() == '\n') break;// Checks for end of line

      in >> num1;

      if(in.get() == '\n') throw file_error("Incorrect input format.",i+2);
      in.unget();

      in >> num2;
    }
}

// Helper
template <class T>
void Polynomial<T>::polycpy(const T* src_order, const T*  src_coeff);
