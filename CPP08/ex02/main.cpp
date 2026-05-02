#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <algorithm>
#include "MutantStack.hpp"

int main( void ) {
    MutantStack<int> mstack;

    std::cout << "== MutantStack basic usage ==" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "== std::list basic usage ==" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it2 = lst.begin();
    std::list<int>::iterator ite2 = lst.end();
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::cout << "== reverse iteration ==" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "== const iteration ==" << std::endl;
    const MutantStack<int> cmstack(mstack);
    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();
    while (cit != cite) {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "== copy is independent ==" << std::endl;
    MutantStack<int> copy(mstack);
    copy.push(999);
    std::cout << "original top: " << mstack.top() << std::endl;
    std::cout << "copy top: " << copy.top() << std::endl;
    std::cout << "original size: " << mstack.size() << std::endl;
    std::cout << "copy size: " << copy.size() << std::endl;

    std::cout << "== empty stack ==" << std::endl;
    MutantStack<int> empty;
    std::cout << "empty? " << (empty.empty() ? "yes" : "no") << std::endl;
    std::cout << "size: " << empty.size() << std::endl;
    std::cout << "begin == end? " << (empty.begin() == empty.end() ? "yes" : "no") << std::endl;

    std::cout << "== std::find with MutantStack ==" << std::endl;
    MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 737);
    if (found != mstack.end())
        std::cout << "found 737 at distance " << std::distance(mstack.begin(), found) << std::endl;
    else
        std::cout << "737 not found" << std::endl;

    std::cout << "== MutantStack with std::string ==" << std::endl;
    MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("mutant");
    sstack.push("world");
    for (MutantStack<std::string>::iterator sit = sstack.begin(); sit != sstack.end(); ++sit)
        std::cout << *sit << std::endl;

    return 0;
}
