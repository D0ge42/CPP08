#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <vector>
#include <iostream>

static int getSpan(int x, int y);

Span::Span(void)
{
}

Span::Span(unsigned int N)
{
  this->_vec = std::vector<int>(N);
}

Span::Span(const Span &other)
{
  (void)other;
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &other)
{
  (void)other;
  return (*this);
}

void Span::addNumber(int num)
{
  this->_vec.push_back(num);
}

int Span::shortestSpan()
{
  int to_compare;
  int sp;
  std::vector<int>::iterator it;

  if (_vec.size() <= 1)
    throw NoSpanFoundException();

  sp = getSpan(_vec[0],_vec[1]);
  std::for_each(_vec.begin(),_vec.end(),abs);

  for (it = _vec.begin(); it != _vec.end(); it++)
  {
    to_compare = getSpan(*it, *(it + 1));
    if (sp > to_compare)
      sp = to_compare;
  }
  return sp;
}


static int getSpan(int x, int y)
{
  return abs(x - y);
}

void Span::printContainer()
{
  std::vector<int>::iterator it;
  std::cout << "Begin: " << *_vec.begin() << std::endl;
  std::cout << "End: " << *_vec.end() << std::endl;


  for (it = _vec.begin(); it != _vec.end(); it++)
  {
    std::cout << *it;
    if (it != (_vec.end()) - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;
}
