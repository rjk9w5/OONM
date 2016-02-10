#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "autoarray.hpp"
#include "polynomial.hpp"

int main()
{
  std::ifstream fin;
  std::vector<polynomial_fnct<int>> p_vec;
  polynomial_fnct<int> p;//, p_input;
  monomial<int> m;
  int ninputs;

  fin.open("notafile.txt");
  // This should work in the driver for polynomial. Yay!!
  fin >> ninputs;
  for(int i=0; i < ninputs; ++i)
  {
    // Check for end of file (in case the input number was too big)
    if(fin.get() && fin.eof()) break;
    fin.unget(); // if the eof was not found, unget the next value

    fin >> p;
    p_vec.push_back(p);
  }
  // Evaluate each polynomial input
  for(auto it: p_vec)
  {
    std::cout << "f(2) = " << it << " = "<< it(2) << '\n';
  }

  // Get some monomial from a polynomial
  m = p_vec[0][3];
  // And evaluate that monomial
  std::cout << m(1) << '\n';

  // Test a bunch of operators
  p = p_vec[1];
  // +=
  p += p;
  std::cout << p << '\n';
  //-= and +
  p -= p_vec[0];
  p = p_vec[1] + p;
  std::cout << p << '\n';

  // Unary -
  std::cout << -p << '\n';
  // Unary ~
  std::cout << ~p << '\n';
  // +
  std::cout << ~p + p << '\n';
  // -
  std::cout << ~p - p << '\n';


  // Close file when finished
  fin.close();

  return 0;
}
