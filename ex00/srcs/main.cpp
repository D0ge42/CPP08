#include "easyfind.hpp"
#include <cstdlib>
#include <deque>
#include <list>
#include <vector>

#define MAX 1000

int main()
{
  srand(time(NULL));


  //############################-- TESTING LIST --##################################//

  std::list<int> list;
  for (int i = 0; i < rand() % 100; i++)
    list.push_back(rand() % MAX);
  list.push_back(4);

  std::cout << "\n\033[1;92mTrying to find a number that exists in the list\033[0m✅" << std::endl;

  try
  {
    std::cout << "Found number: " << *easyfind(list,4) << std::endl;
  }
  catch (ElementNotFoundException &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n\033[1;91mTrying to find a number that does not exists in the list\033[0m⛔" << std::endl;

  try
  {
    std::cout << *easyfind(list,rand() % MAX) << std::endl;
  }
  catch (ElementNotFoundException &e)
  {
    std::cout << e.what() << std::endl;
  }

  //############################-- TESTING VECTORS --##################################//

  std::vector<int> vect;
  for (int i = 0; i < rand() % 100; i++)
    vect.push_back(rand() % MAX);
  vect.push_back(4);

  std::cout << "\n\033[1;92mTrying to find a number that exists in the vect\033[0m✅" << std::endl;

  try
  {
    std::cout << "Found number: " << *easyfind(vect,4) << std::endl;
  }
  catch (ElementNotFoundException &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n\033[1;91mTrying to find a number that does not exists in the vect\033[0m⛔" << std::endl;

  try
  {
    std::cout << *easyfind(vect,rand() % MAX) << std::endl;
  }
  catch (ElementNotFoundException &e)
  {
    std::cout << e.what() << std::endl;
  }

  //############################-- TESTING DEQUE --##################################//

  std::deque<int> deq;
  for (int i = 0; i < rand() % 100; i++)
    deq.push_front(rand() % MAX);
  deq.push_front(4);

  std::cout << "\n\033[1;92mTrying to find a number that exists in the deq\033[0m✅" << std::endl;

  try
  {
    std::cout << "Found number: " << *easyfind(deq,4) << std::endl;
  }
  catch (ElementNotFoundException &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n\033[1;91mTrying to find a number that does not exists in the deq\033[0m⛔" << std::endl;

  try
  {
    std::cout << *easyfind(deq,rand() % MAX) << std::endl;
  }
  catch (ElementNotFoundException &e)
  {
    std::cout << e.what() << std::endl;
  }
}
