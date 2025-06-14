#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
    //###############################SUBJECT MAIN TEST##################################//

    std::cout << "\n\033[1;94mTEST: Basic subject test\033[0m 🐢 " << std::endl;
    MutantStack<int> mstack;
    std::cout << "Pushing 5 into stack" << std::endl;
    mstack.push(5);
    std::cout << "Pushing 17 into stack" << std::endl;
    mstack.push(17);
    std::cout << "Top of stack: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);

    //###############################SUBJECT MAIN TEST##################################//

    std::cout << "\n\033[1;92mTEST: Basic subject test but with list \033[0m 🐢 " << std::endl;
    std::list<int> mlist;
    std::cout << "Pushing: 5" << std::endl;
    mlist.push_back(5);
    std::cout << "Pushing: 17" << std::endl;
    mlist.push_back(17);
    std::cout << "Top of stack: " << *mlist.begin() << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::list<int>::iterator l_it= mlist.begin();
    std::list<int>::iterator l_ite = mlist.end();
    ++l_it;
    --l_it;
    while (l_it != l_ite)
    {
      std::cout << *l_it << std::endl;
      ++l_it;
    }

    //##################################################################################//

    std::cout << "\n\033[1;97mTesting reverse iterator \033[0m 🔥" << std::endl;

    MutantStack<int> mstack1;
    mstack1.push(42);
    mstack1.push(41);
    mstack1.push(-42);
    mstack1.push(-41);
    mstack1.push(0);

    MutantStack<int>::rev_iterator rev_it_begin;
    MutantStack<int>::rev_iterator rev_it_end = mstack1.rend();
    for (rev_it_begin = mstack1.rbegin(); rev_it_begin != rev_it_end; rev_it_begin++)
    {
      // *rev_it_begin += 48;
      std::cout << *rev_it_begin << std::endl;
    }

    //##################################################################################//

    std::cout << "\n\033[1;95mTesting reverse const iterator \033[0m 🔥" << std::endl;

    MutantStack<char> mstack2;
    mstack2.push(97);
    mstack2.push(98);
    mstack2.push(99);
    mstack2.push(100);
    mstack2.push(101);

    MutantStack<char>::const_rev_iterator const_rev_it_begin;
    MutantStack<char>::const_rev_iterator const_rev_it_end = mstack2.rend();
    for (const_rev_it_begin = mstack2.rbegin(); const_rev_it_begin != const_rev_it_end; const_rev_it_begin++)
    {
      std::cout << *const_rev_it_begin << std::endl;
      // *const_rev_it_begin += 48; decommenting this would result in compilation error
    }

    //##################################################################################//

    std::cout << "\n\033[1;95mTesting reverse const iterator on strings \033[0m 🔥" << std::endl;

    MutantStack<std::string> mstack3;
    mstack3.push("Hello");
    mstack3.push("World");
    mstack3.push("How");
    mstack3.push("You");
    mstack3.push("Doing");

    MutantStack<std::string>::const_rev_iterator const_rev_it_begin_str;
    MutantStack<std::string>::const_rev_iterator const_rev_it_end_str = mstack3.rend();
    for (const_rev_it_begin_str = mstack3.rbegin(); const_rev_it_begin_str != const_rev_it_end_str; const_rev_it_begin_str++)
    {
      std::cout << *const_rev_it_begin_str << std::endl;
    }
}
