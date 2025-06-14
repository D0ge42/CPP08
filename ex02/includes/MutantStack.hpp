#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
  public:
    // Constructors
    MutantStack(void);
    MutantStack(const MutantStack &other);

    // Destructors
    ~MutantStack(void);

    // Operators overload
    MutantStack &operator=(const MutantStack &other);

    // Member functions

};

#endif

