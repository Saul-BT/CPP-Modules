#include <algorithm>
#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _members(other._members) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _members  = other._members;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber( int num ) {
    if (this->_members.size() >= this->_maxSize)
        throw std::runtime_error("The container is full");

    this->_members.push_back(num);
}

int Span::shortestSpan( void ) const {
    if (this->_members.size() < 2)
        throw std::runtime_error("Not enough members to compute span");

    std::vector<int> sorted(this->_members);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (unsigned int i = 1; i < sorted.size() - 1; i++) {
        int curSpan = sorted[i + 1] - sorted[i];
        if (curSpan < minSpan)
            minSpan = curSpan;
    }

    return minSpan;
}

int Span::longestSpan( void ) const {
    if (this->_members.size() < 2)
        throw std::runtime_error("Not enough members to compute span");

    int minNum = *std::min_element(this->_members.begin(), this->_members.end());
    int maxNum = *std::max_element(this->_members.begin(), this->_members.end());

    return maxNum - minNum;
}