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

  n = A.get_size(); // Number of vectors in set
  if(n > 0)
  {
    m = A[0].get_size(); // number of elements in each vector

    for(auto Ak: A)
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
      R[k][k] = sqrt(Q[k]*Q[k]);

      //std::cout << "R[" << k << "][" << k << "] = " << R[k][k] << std::endl;

      // Update kth vector
      for(int j=0; j<m; ++j)
      {
        Q[k][j] = Q[k][j]/R[k][k];
      }

      // Udate the rest of the vector set
      for(int j=k+1; j<n; ++j)
      {
        R[k][j] = (Q[j]*Q[k]);
        for(int i=0; i<m; ++i)
        {
          Q[j][i] = Q[j][i] - R[k][j]*Q[k][i];
        }
      }
    }
  }
  //std::cout << Q << std::endl;
  std::cout << "COMPLETE QR DECOMP\n";
  return;
}

