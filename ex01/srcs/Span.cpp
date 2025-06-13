#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <vector>
#include <iostream>

static int getSpan(int x, int y);

void Span::addNumber(int num)
{
  if ((this->_vec.size() + 1) <= this->_maxSize)
    this->_vec.push_back(num);
  else
    throw TooManyNumbersException();
}

int Span::shortestSpan()
{
  int to_compare;
  int sp;
  std::vector<int>::iterator it;

  if (_vec.size() <= 1)
    throw NoSpanFoundException();

  std::vector<int> sorted = _vec;
  std::sort(sorted.begin(),sorted.end());

  sp = getSpan(sorted[1],sorted[0]);

  for (it = sorted.begin() + 2; it != sorted.end(); it++)
  {
    to_compare = getSpan(*it, *(it - 1));
    if (sp > to_compare)
      sp = to_compare;
  }
  return sp;
}

int Span::longestSpan()
{
  std::vector<int>::iterator it;

  if (_vec.size() <= 1)
    throw NoSpanFoundException();

  int maxVal = *std::max_element(_vec.begin(),_vec.end());
  int minVal = *std::min_element(_vec.begin(),_vec.end());

  return maxVal - minVal;
}


static int getSpan(int x, int y)
{
  return abs(x - y);
}

void Span::printContainer()
{
  std::vector<int>::iterator it;

  std::vector<int> sorted = _vec;
  std::sort(sorted.begin(),sorted.end());

  std::cout << "\n\033[1;96mContainer: \033[0m ";
  for (it = sorted.begin(); it != sorted.end(); it++) {
    std::cout << *it;
    if (it != (sorted.end()) - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;
}

/* Constructors && destructors && overloaded operators*/

Span::Span(void)
{
}

Span::Span(unsigned int N)
{
  if (N <= 1)
    throw NoSpanFoundException();
  this->_maxSize = N;
  this->_vec.reserve(N);
}

Span::Span(const Span &other)
{
  this->_vec = other._vec;
  this->_maxSize = other._maxSize;
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &other)
{
  this->_vec = other._vec;
  this->_maxSize = other._maxSize;
  return (*this);
}
