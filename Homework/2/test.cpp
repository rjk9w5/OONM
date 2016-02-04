#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <exception>

struct file_not_found: std::runtime_error
{
  file_not_found(): runtime_error("") {};
  const char* what() const noexcept
  {
    return "File not found!\n";
  }
};

struct file_error: std::exception
{
  public:
    file_error(){}
    file_error(char* what_msg):
      msg(what_msg),
      line(-1) {}
    file_error(char* what_msg, const int ln):
      msg(what_msg),
      line(ln) {}
    const char* what() const noexcept {return msg;}
    const int onLine() const {return line;}
  private:
    char* msg;
    int line;
};

int main()
{
  int nInput, nRow, num1, num2;

  std::ifstream fin;

  fin.open("notafile.txt");
  // This should work in the driver for polynomial. Yay!!
  try
  {
    // Check if file opened correctly. If not through exception
    if(!fin.is_open()) throw file_error("File not found");

    // Get first input for number of max lines to follow
    if(fin.eof()) throw file_error("Empty file!");
    fin >> nInput;
    std::cout << nInput << '\n';

    // Loops for given no. of input while also checking the eof is not
    // reached. Assumes that every line ends with '\n' and has an odd
    // number of values.
    for(int i=0; !fin.eof() && i < nInput; ++i)
    {
      //std::cout << "Line: " << i+2 << '\n';
      fin >> nRow;
      for(int j=0;j < nRow; ++j)
      {
        if(fin.get() == '\n') break;// Checks for end of line

        fin >> num1;

        if(fin.get() == '\n') throw file_error("Incorrect input format.",i+2);
        fin.unget();

        fin >> num2;
      }
      // End read polynomial from line
      //std::cout << '\n';
    }
  }
  catch(const file_error& err)
  {
    fin.close();
    std::cerr << err.what();
    if(err.onLine() > 0)
    {
      std::cerr << " on line: " << err.onLine() << '\n';
    }
  }
  
  // Close file when finished
  fin.close();

  return 0;
}
