/*
 * driver.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: ryan
 */

/*
 *    function: main(int, char**)
 *       brief: The main function
 *         pre: Must have one input file
 *        post: Runs the main driver for the assignment
 *      return: 0 for successful run
 */

#include <fstream>
#include <iostream>
#include "vector.h"
#include "qr_decomp.h"
#include "nl_exceptions.h"

int main(int argc, char* argv[])
{
  oonm::Vector<oonm::Vector<double>> avec;
  oonm::Vector<oonm::Vector<double>>* QR;
  std::ifstream fin;
  nl::qr_decomp<double> QR_decomp;
  size_t actual_size=0;
  size_t v_size;

  try
  {
    std::cout << "File to read is: " << argv[1] << '\n';

    fin.open(argv[1]);

    if(!fin.is_open()) throw nl::FatalError("File could not be opened!");

    fin >> v_size;
    std::cout << v_size << '\n';
    avec.set_size(v_size);
    for(size_t i=0; i<v_size && fin.good(); ++i)
    {
      avec[i].set_size(v_size);
      fin >> avec[i];
      actual_size++;
    }
    fin.close();

    if(actual_size != v_size)
      throw nl::FatalError("The input file gives the wrong size!\n");

    std::cout << "The sum of the first two vectors read: \n";
    std::cout << (avec[1] + avec[0]) << std::endl<< std::endl;

    std::cout << "The difference of the first two vectors read: \n";
    std::cout << (avec[1] - avec[0]) << std::endl<< std::endl;

    std::cout << "The inner product of the first two vectors read: \n";
    std::cout << (avec[1] * avec[0]) << std::endl<< std::endl;

    std::cout << "Demonstrating the output of a vector of scalars: \n";
    std::cout << avec[0] << std::endl<< std::endl;

    std::cout << "Demonstrating the output of a vector of vectors: \n";
    std::cout << avec << std::endl<< std::endl;

    std::cout << "Demonstrating the [] operator (display only here): \n";
    std::cout << avec[0][0] << std::endl<< std::endl;

    std::cout << "Computing QR decomposition (Modified Gram-Schmidt): \n";
    QR = QR_decomp(avec);
    std::cout << "The Q matrix is: \n";
    std::cout << QR[0] << std::endl<< std::endl;
    std::cout << "The R matrix is: \n";
    std::cout << QR[1] << std::endl<< std::endl;

    std::cout << "The n^2 dot products of the Qi's: \n";
    actual_size=1;
    for(auto& Qj: QR[0])
    {
      // Demonstrate Normaility of each vector
      std::cout << "(Q" << std::setw(3) << actual_size
                << ",Q" << std::setw(3) <<  actual_size << ")  =  "
                << Qj*Qj << '\n';
      //for(auto& Qi: QR[0])
        // Demonstrates the Orthogonality of each vector to all others
        //std::cout << Qj*Qi << '\n';
      actual_size++;
    }
  }
  catch(nl::FatalError& except)
  {
    std::cerr << "There was an error...and it is all your fault!" << std::endl;
    std::cerr << except.what() << std::endl;
  }

  delete[] QR;

  return 0;
}


