#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "polynomial.hpp"
#include "infinity_norm.hpp"

int main()
{
  std::ifstream fin;
  std::vector<polynomial_fnct<double>> p_vec;
  polynomial_fnct<double> p;//, p_input;
  monomial<double> m;
  int ninputs;

  std::string input_file_name("notafile.txt");

  fin.open(input_file_name);
  // Read input file
  std::cout << "Reading from input file: " << input_file_name << '\n';
  fin >> ninputs;
  for(int i=0; i < ninputs; ++i)
  {
    // Check for end of file (in case the input number was too big)
    if(fin.get() && fin.eof()) break;
    fin.unget(); // if the eof was not found, unget the next value

    fin >> p;
    p_vec.push_back(p);
  }
  // Evaluate each polynomial input and output
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
  std::cout << "Test Unary negation:\n\n";
  std::cout << "p: " << p << '\n';
  std::cout <<"-p: " << -p << '\n';
  // Unary ~
  std::cout << "Test Unary negation:\n\n";
  std::cout << "p: " << p << '\n';
  std::cout <<"~p: " << ~p << '\n';
  // +
  std::cout << "Test polynomial addition: \n\n";
  std::cout << ~p << "\n -plus- \n" << p << " = \n";
  std::cout << ~p + p << '\n';
  // -
  std::cout << "Test polynomial addition: \n\n";
  std::cout << ~p << "\n -minus- \n" << p << " = \n";
  std::cout << ~p - p << '\n';

  // Some additional unit testing yay!
  std::cout << "Test ~p(5) + -p(4):\n";
  std::cout << ~p << "|5 = " << (~p)(5) << "\n";
  std::cout << " -plus- \n";
  std::cout << -p << "|4 = " << (-p)(4) << "\n";
  std::cout << "________________________________________________\n";
  std::cout << ((~p) + (-p)) << (~p)(5) + (-p)(4) << '\n';

  std::cout << (p==p?"yes":"no") << '\n';
  if(p == p)
    std::cout << "polynomial_fnct p is equal to polynomial_fnct p!\n";
  else
    std::cout << "Really really really bad.....\n";

  if(p != p_vec[5])
    std::cout << "polynomial_fnct p is not equal to polynomial_fnct p_vec[5]\n";

  infinity_norm<polynomial_fnct<double>> get_norm;

  std::cout << get_norm(p_vec) << '\n';


  // Close file when finished
  fin.close();

  return 0;
}
