/* ************************************************************************** *\
 * linearsystem_solversI.hpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */


template <class Ele_T>
oonm::Vector<Ele_T> oonm::gaussian_solver<Ele_T>::operator ()(
    oonm::Matrix_type<Ele_T> const &Ain,
    oonm::Vector<Ele_T> b)
{
  if(Ain.N() != b.get_size() || Ain.N() != Ain.M())
  {
    throw oonm::FatalError(
        "gaussian_solver<Ele_T>::operator (): Dimension mismatch");
  }

  std::shared_ptr<oonm::Matrix_type<Ele_T>> A = Ain.clone();
  std::size_t N = b.get_size();
  std::size_t rmax, cmax;
  oonm::Vector<Ele_T> x, tmp;
  oonm::Vector<std::size_t> pivot_track;
  if(full_pivot)
  {
    pivot_track.set_size(N);
    tmp.set_size(N);
    for(std::size_t i=0; i<N; ++i)
      pivot_track[i] = i;
  }
  Ele_T mk;
  for(std::size_t k=0; k<(N-1); ++k)
  {
    if(partial_pivot)
    {
      rmax = k;
      for(int i=k; i<N; ++i)
      {
        if(abs(A -> operator()(i,k)) > abs(A -> operator()(rmax,k)))
          rmax = i;
      }
      // Pivot
      if(rmax != k)
      {
        A -> swapr(k,rmax);
        b.ele_swap(k,rmax);
      }
    }
    else if(full_pivot)
    {
      rmax = k;
      cmax = k;
      for(int i=k; i<N; ++i)
      {
        for(std::size_t j=k; j<N; ++j)
        {
          if(abs(A -> operator()(i,j)) > abs(A -> operator()(rmax,cmax)))
          {
            rmax = i;
            cmax = j;
          }
        }
      }
      // Pivot
      if(rmax != k)
      {
        A -> swapr(k,rmax);
        b.ele_swap(k,rmax);
      }
      if(cmax !=k)
      {
        A -> swapc(k,cmax);
        pivot_track.ele_swap(k,cmax);
      }
    }

    for(std::size_t i=k+1; i<N; ++i)
    {
      mk = A -> operator()(i,k)/A -> operator()(k,k);
      for(std::size_t j=0; j<N; ++j)
      {
        A -> operator()(i,j) -= mk*A -> operator()(k,j);
      }
      b[i] = b[i] - mk*b[k];
    }
  }

  x = backsub(*A,b);
  if(full_pivot)
  {
    for(std::size_t i=0; i<N; ++i)
    {
      tmp[pivot_track[i]] = x[i];
    }
    x = tmp;
  }

  return x;
}

template <class Ele_T>
oonm::Vector<Ele_T>
oonm::TDMA<Ele_T>::operator ()(
    oonm::Matrix_type<Ele_T> const &Ain,
    oonm::Vector<Ele_T> b)
{
    if(Ain.N() != b.get_size())
    {
      throw oonm::FatalError(
          "TDMA<Ele_T>::operator (): Dimension mismatch");
    }

    std::shared_ptr<oonm::Matrix_type<Ele_T>> A = Ain.clone();
    std::size_t N = b.get_size();
    oonm::Vector<Ele_T> sol(N);
    Ele_T m;

    for(std::size_t k=1; k<N; ++k)
    {
      m = A -> operator()(k,k-1)/A -> operator()(k-1,k-1);
      A -> operator()(k,k) -= m*A -> operator()(k-1,k);
      b[k] -= m*b[k-1];
    }
    sol[N-1] = b[N-1]/A->operator()(N-1,N-1);
    for(std::size_t k=N-2; k>0; --k)
    {
      sol[k] = (b[k] - A->operator()(k,k+1)*sol[k+1])/A->operator()(k,k);
    }

    return sol;
}



template <class Ele_T>
oonm::Vector<Ele_T> oonm::sles<Ele_T>::backsub(
    oonm::Matrix_type<Ele_T> const &A,
    oonm::Vector<Ele_T> const &b)
{
  if(A.get_nrows() != b.get_size())
  {
    throw oonm::FatalError(
        "sle<Ele_T>::backsub: Dimension mismatch");
  }
  std::size_t n = b.get_size();
  oonm::Vector<Ele_T> x(n);
  Ele_T sm;

  x[n-1] = b[n-1]/A(n-1,n-1);

  for(std::size_t i=n-2; i<static_cast<std::size_t>(-1); --i)
  {
    sm=0;
    for(std::size_t j=i+1; j<n; ++j)
    {
      sm += A(i,j)*x[j];
    }

    x[i] = (b[i] - sm)/A(i,i);
  }

  return x;
}
