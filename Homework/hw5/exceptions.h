/*
 * nl_exceptions.h
 *
 *  Created on: Feb 25, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
 */

/*
 *       class: FatalError
 *       brief: Exception handling class.
 */

/*
 *    function: FatalError( char* or std::string)
 *       brief: Constructor that sets the message for what()
 *         pre: There must be at least and empty string (ie. "")
 *        post: Constructs an exception object to be thrown
 *      return: None
 */

/*
 *    function: ~FatalError()
 *       brief: Destructor
 *         pre: None
 *        post: Destructors an object
 *      return: None
 */

/*
 *    function: what()
 *       brief: The getter for the exception message
 *         pre: None
 *        post: Returns the Exception message
 *      return: Returns the Exception message
 */

#ifndef NL_EXCEPTIONS_H_
#define NL_EXCEPTIONS_H_

#include <string>
#include <exception>

namespace oonm
{
  class Exception
  {
    public:
    virtual ~Exception() {}

    virtual const std::string errMsg() const noexcept = 0;

    virtual Exception& operator << (std::string const &msg) = 0;
  };

  class RangeException: public Exception
  {
    public:
      RangeException(): msg_() {}
      virtual ~RangeException() {}

      virtual const std::string errMsg() const noexcept
          {return "Range Error: " + msg_ + " \n";};

      virtual Exception& operator << (std::string const &msg)
      {
        msg_ = msg_ + msg;
        return *this;
      }

    private:
      std::string msg_;
  };

  class DimensionMismatch: public Exception
  {
    public:
      DimensionMismatch(): msg_() {}
      virtual ~DimensionMismatch() {}

      virtual const std::string errMsg() const noexcept
        {return "Dimension Error: " + msg_ + " \n";};

      virtual Exception& operator << (std::string const &msg)
      {
        msg_ = msg_ + msg;
        return *this;
      }

    private:
      std::string msg_;
  };

  class FatalError: std::exception
  {
    public:

      explicit FatalError(const char* msg): msg_(msg)
      {
      }

      explicit FatalError(const std::string& msg): msg_(msg)
      {
      }

      virtual ~FatalError() throw (){}

      virtual const char* what() const throw()
      {
        return msg_.c_str();
      }

    protected:
      std::string msg_;
  };
}



#endif /* NL_EXCEPTIONS_H_ */
