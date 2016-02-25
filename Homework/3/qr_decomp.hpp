/*
 * qr_decomp.hpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
 */

template <class T>
void qr_decomp<T>::operator() (const oonm::Vector<oonm::Vector<T>>& A,
            oonm::Vector<oonm::Vector<T>>& Q,
            oonm::Vector<oonm::Vector<T>>& R)
{
  size_t n,m;
  T tmp;
  Norm2<oonm::Vector<T>> l2_norm;

  n = A.get_size(); // Number of vectors in set
  if(n > 0)
  {
    m = A[0].get_size(); // number of elements in each vector

    for(auto& Ak: A)
    {
      // Check to make sure each vector in the set is of the same size
      if(Ak.get_size() != m) throw std::exception();
    }
    // Reset memory for Q and R vector sets
    R.reuse(n);
    for(int i=0; i<n; ++i)
      R[i].reuse(n);

    Q = A;

    //std::cout << Q << std::endl;

    for(int k=0; k<n; ++k)
    {
      // Udate the rest of the vector set with normalized vector
      for(int j=k+1; j<n; ++j)
      {
        R[k][j] = (Q[k]*Q[j]);

        Q[j] = Q[j] - R[k][j]*Q[j]/(Q[j]*Q[j]);
      }

      // Normalize Current vector after updating others
      R[k][k] = l2_norm(Q[k]);
      Q[k] = Q[k]/(R[k][k]);
    }
  }
  std::cout << Q << std::endl;
  std::cout << "COMPLETE QR DECOMP\n";
  return;
}

