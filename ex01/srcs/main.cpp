#include "Span.hpp"
#include <iostream>

int main()
{
  std::cout << "\n\033[1;94mTrying valid container with 5 numbers\033[0m ✅" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  sp.printContainer();
  std::cout << "\033[1;91mShortestspan\033[0m:" << sp.shortestSpan() << std::endl;
  std::cout << "\033[1;92mLongestSpan\033[0m:" << sp.longestSpan() << std::endl;


  std::cout << "\n\033[1;94mTrying valid container with 5 numbers\033[0m ✅" << std::endl;
  Span sp1 = Span(5);
  sp1.addNumber(2);
  sp1.addNumber(4);
  sp1.addNumber(5);
  sp1.addNumber(9);
  sp1.addNumber(11);
  sp1.printContainer();
  std::cout << "\033[1;91mShortestspan\033[0m: " << sp1.shortestSpan() << std::endl;
  std::cout << "\033[1;92mLongestSpan\033[0m: " << sp1.longestSpan() << std::endl;


  std::cout << "\n\033[1;94mTrying non-valid container with 1 number\033[0m ⛔" << std::endl;
  try
  {
    Span sp2 = Span(1);
  }
  catch (Span::NoSpanFoundException &e)
  {
    std::cout << e.what() << std::endl;
  }


  std::cout << "\n\033[1;94mTrying to add max_size +1 elements \033[0m ⛔" << std::endl;
  try
  {
    Span sp2 = Span(2);
    sp2.addNumber(3);
    sp2.addNumber(3);
    sp2.addNumber(3);
  }
  catch (Span::TooManyNumbersException &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << '\n';

  return 0;
}

