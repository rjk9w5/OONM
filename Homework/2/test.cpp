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
    fin >> p;
    p_vec.push_back(p);
  }

  //std::cin >> p_input;

  //std::cout << p_input(3) << '\n';

  for(auto it: p_vec)
  {
    std::cout << "f(2) = " << it << " = "<< it(2) << '\n';
  }

  m = p_vec[0][3];

  std::cout << m(1) << '\n';

  p = p_vec[1];
  p += p;
  std::cout << p << '\n';
  p -= p_vec[0];
  p = p_vec[1] + p;
  std::cout << p << '\n';

  std::cout << -p << '\n';
  std::cout << ~p << '\n';
  std::cout << ~p + p << '\n';
  std::cout << ~p - p << '\n';


  // Close file when finished
  fin.close();

  return 0;
}
