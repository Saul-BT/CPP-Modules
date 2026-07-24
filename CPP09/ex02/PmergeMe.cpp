#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sys/time.h>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe & other) : _vec(other._vec), _deq(other._deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe & other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositiveInt(const std::string & tok, int & out) {
    if (tok.empty() || tok.length() > 10)
        return false;
    for (std::size_t i = 0; i < tok.length(); ++i)
        if (tok[i] < '0' || tok[i] > '9')
            return false;

    long value = 0;
    for (std::size_t i = 0; i < tok.length(); ++i)
        value = value * 10 + (tok[i] - '0');
    if (value < 1 || value > 2147483647L)
        return false;

    out = static_cast<int>(value);
    return true;
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> & src) const {
    if (src.size() <= 1)
        return src;

    // Make pairs (winner, loser)
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = (src.size() % 2 != 0);
    int odd = hasOdd ? src[src.size() - 1] : 0;
    for (std::size_t i = 0; i + 1 < src.size(); i += 2) {
        if (src[i] > src[i + 1])
            pairs.push_back(std::make_pair(src[i], src[i + 1]));
        else
            pairs.push_back(std::make_pair(src[i + 1], src[i]));
    }

    // Recursion with winners
    std::vector<int> bigs;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        bigs.push_back(pairs[i].first);
    std::vector<int> chain = this->sortVector(bigs);

    // Re-pair loser with the chain of winners
    std::vector<int> pend;
    std::vector<bool> used(pairs.size(), false);
    for (std::size_t i = 0; i < chain.size(); ++i) {
        for (std::size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == chain[i]) {
                pend.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    // Add first loser at the begining
    chain.insert(chain.begin(), pend[0]);
    std::size_t inserted = 1;

    // Jacobsthal groups (t_k = 2^k − t_{k−1} → 3, 5, 11, 21, …), descendants
    std::size_t tPrev = 1;
    std::size_t pow2 = 4;
    while (tPrev < pend.size()) {
        std::size_t t = pow2 - tPrev;
        std::size_t top = t < pend.size() ? t : pend.size();
        for (std::size_t j = top; j > tPrev; --j) {
            std::size_t bound = (j - 1) + inserted;
            if (bound > chain.size())
                bound = chain.size();
            std::vector<int>::iterator pos =
                std::upper_bound(chain.begin(), chain.begin() + bound, pend[j - 1]);
            chain.insert(pos, pend[j - 1]);
            ++inserted;
        }
        tPrev = t;
        pow2 *= 2;
    }

    // Insert the pending odd
    if (hasOdd) {
        std::vector<int>::iterator pos = std::upper_bound(chain.begin(), chain.end(), odd);
        chain.insert(pos, odd);
    }
    return chain;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> & src) const {
    if (src.size() <= 1)
        return src;

    std::deque<std::pair<int, int> > pairs;
    bool hasOdd = (src.size() % 2 != 0);
    int odd = hasOdd ? src[src.size() - 1] : 0;
    for (std::size_t i = 0; i + 1 < src.size(); i += 2) {
        if (src[i] > src[i + 1])
            pairs.push_back(std::make_pair(src[i], src[i + 1]));
        else
            pairs.push_back(std::make_pair(src[i + 1], src[i]));
    }

    std::deque<int> bigs;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        bigs.push_back(pairs[i].first);
    std::deque<int> chain = this->sortDeque(bigs);

    std::deque<int> pend;
    std::deque<bool> used(pairs.size(), false);
    for (std::size_t i = 0; i < chain.size(); ++i) {
        for (std::size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == chain[i]) {
                pend.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    chain.push_front(pend[0]);
    std::size_t inserted = 1;

    std::size_t tPrev = 1;
    std::size_t pow2 = 4;
    while (tPrev < pend.size()) {
        std::size_t t = pow2 - tPrev;
        std::size_t top = t < pend.size() ? t : pend.size();
        for (std::size_t j = top; j > tPrev; --j) {
            std::size_t bound = (j - 1) + inserted;
            if (bound > chain.size())
                bound = chain.size();
            std::deque<int>::iterator pos =
                std::upper_bound(chain.begin(), chain.begin() + bound, pend[j - 1]);
            chain.insert(pos, pend[j - 1]);
            ++inserted;
        }
        tPrev = t;
        pow2 *= 2;
    }

    if (hasOdd) {
        std::deque<int>::iterator pos = std::upper_bound(chain.begin(), chain.end(), odd);
        chain.insert(pos, odd);
    }
    return chain;
}

bool PmergeMe::run(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    for (int i = 1; i < argc; ++i) {
        int value;
        if (!PmergeMe::isPositiveInt(argv[i], value)) {
            std::cerr << "Error" << std::endl;
            return false;
        }
    }

    std::cout << "Before:";
    for (int i = 1; i < argc; ++i)
        std::cout << " " << argv[i];
    std::cout << std::endl;

    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    this->_vec.clear();
    for (int i = 1; i < argc; ++i) {
        int value;
        PmergeMe::isPositiveInt(argv[i], value);
        this->_vec.push_back(value);
    }
    std::vector<int> sortedVec = this->sortVector(this->_vec);
    gettimeofday(&t1, NULL);
    double usVec = (t1.tv_sec - t0.tv_sec) * 1e6 + (t1.tv_usec - t0.tv_usec);

    gettimeofday(&t0, NULL);
    this->_deq.clear();
    for (int i = 1; i < argc; ++i) {
        int value;
        PmergeMe::isPositiveInt(argv[i], value);
        this->_deq.push_back(value);
    }
    std::deque<int> sortedDeq = this->sortDeque(this->_deq);
    gettimeofday(&t1, NULL);
    double usDeq = (t1.tv_sec - t0.tv_sec) * 1e6 + (t1.tv_usec - t0.tv_usec);

    std::cout << "After:";
    for (std::size_t i = 0; i < sortedVec.size(); ++i)
        std::cout << " " << sortedVec[i];
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Time to process a range of " << sortedVec.size()
              << " elements with std::vector : " << usVec << " us" << std::endl;
    std::cout << "Time to process a range of " << sortedDeq.size()
              << " elements with std::deque : " << usDeq << " us" << std::endl;
    return true;
}
