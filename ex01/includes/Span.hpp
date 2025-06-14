#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <sstream>
#include <vector>


class Span
{
  private:
    std::vector<int> _vec;
    unsigned int _maxSize;

  public:
    Span(void);
    Span(unsigned int N);
    Span(const Span &other);
    ~Span(void);

    Span &operator=(const Span &other);
    void addNumber(int num);
    // void addMultipleNumbers(int *array, int num_of_elements);
    void addMultipleNumbers(std::vector<int> to_add);
    int shortestSpan();
    int longestSpan();
    void printContainer();

    class TooManyNumbersException: public std::exception
    {
      public:
        const char *what() const throw()
        {
          return "TooManyNumbersException:: You've reached the maximum size of numbers in the container";
        }
    };

    class NoSpanFoundException: public std::exception
    {
      public:
        const char *what() const throw()
        {
          return "NoSpanFoundException:: Couldn't find a span. Either the container is empty or it only contains 1 element.";
        }
    };

};

#endif
