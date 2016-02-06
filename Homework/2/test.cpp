#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "polynomial.hpp"


int main()
{
  std::ifstream fin;
  Polynomial<int> p;


  fin.open("notafile.txt");
  // This should work in the driver for polynomial. Yay!!
  try
  {
    fin >> p;

    std::cout << p << '=' << p(2);
  }
  catch(const file_error& err)
  {
    fin.close();
    std::cerr << err.what();
  }
  
  // Close file when finished
  fin.close();

  return 0;
}
