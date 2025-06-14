#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, class container=std::deque<T> >
class MutantStack: public std::stack<T>
{
  public:
    // Constructors
    MutantStack(void){}
    MutantStack(const MutantStack &other){*this = other;}

    // Destructors
    ~MutantStack(void){}

    // Operators overload
    MutantStack &operator=(const MutantStack &other);

    // Typedef of underlying container of std::stack.
    // stack act as a wrapper to the underlying container but it also provides LIFO approach.
    // (Last in first out) which is the standard stack approach.

    typedef typename container::iterator iterator;
    typedef typename container::const_iterator const_iterator;
    typedef typename container::reverse_iterator rev_iterator;
    typedef typename container::const_reverse_iterator const_rev_iterator;

    iterator begin()
    {
      return this->c.begin();
    }

    iterator end()
    {
      return this->c.end();
    }

    rev_iterator rbegin()
    {
      return this->c.rbegin();
    }


    rev_iterator rend()
    {
      return this->c.rend();
    }

    const_rev_iterator crbegin()
    {
      return this->c.rbegin();
    }

    const_rev_iterator crend()
    {
      return this->c.rend();
    }


};

#endif

