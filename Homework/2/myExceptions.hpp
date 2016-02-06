/*
 * myExceptions.hpp
 *
 *  Created on: Feb 6, 2016
 *      Author: ryan
 */

#ifndef HOMEWORK_2_MYEXCEPTIONS_HPP_
#define HOMEWORK_2_MYEXCEPTIONS_HPP_

#include <exception>

struct file_error: std::exception
{
  public:
    file_error():
      msg(""),
      line(-1){}
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



#endif /* HOMEWORK_2_MYEXCEPTIONS_HPP_ */
