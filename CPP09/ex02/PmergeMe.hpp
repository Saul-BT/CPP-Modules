#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {

private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    static bool isPositiveInt(const std::string &, int &);
    std::vector<int> sortVector(const std::vector<int> &) const;
    std::deque<int> sortDeque(const std::deque<int> &) const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &);
    PmergeMe &operator=(const PmergeMe &);
    ~PmergeMe();

    bool run(int argc, char **argv);
};

#endif
