#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <sstream>
#include <vector>


class Span
{
  private:
    std::vector<int> _vec;

  public:
    Span(void);
    Span(unsigned int N);
    Span(const Span &other);
    ~Span(void);

    Span &operator=(const Span &other);
    void addNumber(int num);
    void addMultipleNumbers();
    int shortestSpan();
    int longestSpan();
    void printContainer();

    class TooManyNumbersException: public std::exception
    {
      const char *what() const throw()
      {
        return "TooManyNumbersException:: You've reached the maximum size of numbers in the container";
      }
    };

    class NoSpanFoundException: public std::exception
    {
      const char *what() const throw()
      {
        return "NoSpanFoundException:: Couldn't find a span. Either the container is empty or it only contains 1 element.";
      }
    };

};

#endif
