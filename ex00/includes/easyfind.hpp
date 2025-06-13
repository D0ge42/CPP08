#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>

class ElementNotFoundException: public std::exception
{
  private:
    std::string _message;

  public:

    ElementNotFoundException(int y)
    {
      std::ostringstream oss;
      oss << "ElementNotFoundException:: couldn't find '" << y << "' in given container\n";
      _message = oss.str();
    }


    virtual const char *what() const  throw()
    {
      return _message.c_str();
    }

    virtual ~ElementNotFoundException() throw() {};
};

template <typename T>
typename T::iterator easyfind(T &x,int y)
{
  typename T::iterator it;

  it = std::find(x.begin(),x.end(),y);
  if (it  == x.end())
    throw ElementNotFoundException(y);
  else
    return it;
}
