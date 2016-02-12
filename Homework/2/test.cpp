#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "polynomial.hpp"
#include "infinity_norm.hpp"

int main(int argc, char *argv[])
{
  std::ifstream fin;
  std::vector<polynomial_fnct<int>> p_vec;
  polynomial_fnct<int> p;//, p_input;
  int ninputs;

try
{
  if(argc != 2) throw std::invalid_argument("Invalid inputs to main!");
  fin.open(argv[1]);
  if(!fin.is_open()) throw std::invalid_argument("File not found!");
  // Read input file
  std::cout << "Reading from input file: " << argv[1] << '\n';
  fin >> ninputs;
  for(int i=0; i < ninputs; ++i)
  {
    // Check for end of file (in case the input number was too big)
    if(fin.get() && fin.eof()) break;
    fin.unget(); // if the eof was not found, unget the next value

    fin >> p;
    p_vec.push_back(p);
  }
  std::cout << "Read success!\n\n";

  // Output first two polynomials
  std::cout << "Polynomial 0: ";
  std::cout << p_vec[0] << std::endl;
  std::cout << "Polynomial 1: ";
  std::cout << p_vec[1] << std::endl;

  // Output p1+=p2
  std::cout << "\np1+=p2\n";
  p_vec[1]+=p_vec[2];
  std::cout << p_vec[1] << std::endl;

  // Output -p1
  std::cout << "\n-p1\n";
  std::cout << -p_vec[1] << std::endl;

  // Output p1(-1)
  std::cout << "\np1(-1)\n";
  std::cout << p_vec[1](-1) << std::endl;

  // Output 4*p3
  std::cout << "\n4*p3\n";
  std::cout << 4*(p_vec[3]) << std::endl;

  // Output (~p4)(2)
  std::cout << "\n~p4(2)\n";
  std::cout << (~p_vec[4])(2) << std::endl;


  // Apply infinity norm to entire data set
  std::cout << "\nTest infinity norm functor: \n";
  infinity_norm<polynomial_fnct<int>> get_norm;
  std::cout << "The infinity norm of the set is: ";
  std::cout << get_norm(p_vec) << '\n';
  std::cout << "\nAnd the magnitude of each input polynomial is:\n";
  for(auto poly: p_vec)
    std::cout << poly.magnitude() << std::endl;


// Ryan's Tests
//  std::cout << std::endl;
//  // Evaluate each polynomial input and output
//  std::cout << "Test output operator << and evaluator operator():\n";
//  for(auto it: p_vec)
//  {
//    std::cout << "f(2) = " << it << " = "<< it(2) << '\n';
//  }
//  std::cout << std::endl;
//
//  // Get some monomial from a polynomial
//  std::cout << "Test operator[]:" << "\n**Get the 4th element in the"
//      " first input polynomial**\n";
//  p = p_vec[0][3];
//  std::cout << p_vec[0] << std::endl;
//  std::cout << p << '\n' << std::endl;
//
//  // Unary -
//  std::cout << "Test Unary operator-: \n";
//  std::cout << "p: " << p << '\n';
//  std::cout <<"-p: " << -p << '\n' << std::endl;
//  // Unary ~
//  std::cout << "Test Dumb operator~:\n";
//  std::cout << "p: " << p << '\n';
//  std::cout <<"~p: " << ~p << '\n' << std::endl;
//  // +
//  std::cout << "Test polynomial addition: \n";
//  std::cout << ~p << "\n -plus- \n" << p << " = \n";
//  std::cout << "____________________________________________________________\n";
//  std::cout << ~p + p << '\n' << std::endl;
//  // -
//  std::cout << "Test polynomial addition: \n";
//  std::cout << ~p << "\n -minus- \n" << p << " = \n";
//  std::cout << "____________________________________________________________\n";
//  std::cout << ~p - p << '\n' << std::endl;
//
//  // Some additional unit testing yay!
//  std::cout << "Test ~p(5) + -p(4):\n";
//  std::cout << ~p << "|5 = " << (~p)(5) << "\n";
//  std::cout << " -plus- \n";
//  std::cout << -p << "|4 = " << (-p)(4) << "\n";
//  std::cout << "____________________________________________________________\n";
//  std::cout << ((~p) + (-p)) << (~p)(5) + (-p)(4) << '\n';
//
//  // +=
//  std::cout << "Test operator+=: \n";
//  std::cout << p_vec[3] << '\n' << " +=\n" << p_vec[3] << '\n';
//  std::cout << "____________________________________________________________\n";
//  p_vec[3] += p_vec[3];
//  std::cout << p_vec[3] << '\n' << std::endl;
//  //-= and +
//  std::cout << "Test operator-=: \n";
//  std::cout << p_vec[4] << '\n' << " +=\n" << p_vec[4] << '\n';
//  std::cout << "____________________________________________________________\n";
//  p_vec[4] += p_vec[4];
//  std::cout << p_vec[4] << '\n' << std::endl;
//
//  std::cout << "Test operator==: \n";
//  std::cout << p << "\n == \n" << p << std::endl;
//  std::cout << (p==p?"True":"False") << '\n' << std::endl;
//
//  std::cout << "Test operator!=: \n";
//  std::cout << p_vec[6] << "\n == \n" << p << std::endl;
//  std::cout << (p!=p?"True":"False") << '\n' << std::endl;
//
//  // Close file when finished
//  fin.close();
}
catch(std::invalid_argument& ia)
{
  std::cerr << ia.what() << std::endl;
}

  return 0;
}
