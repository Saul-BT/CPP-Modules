#include <algorithm>
#include <limits>
#include "Span.hpp"

Span::Span() : _maxSize(0) {}

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
    if (this->_members.size() >= static_cast<std::size_t>(this->_maxSize))
        throw std::runtime_error("The container is full");

    this->_members.push_back(num);
}

int Span::shortestSpan( void ) const {
    if (this->_members.size() < 2)
        throw std::runtime_error("Not enough members to compute span");

    std::vector<int> sorted(this->_members);
    std::sort(sorted.begin(), sorted.end());

    long long minSpan = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
    for (std::size_t i = 1; i < sorted.size() - 1; i++) {
        long long curSpan = static_cast<long long>(sorted[i + 1]) - static_cast<long long>(sorted[i]);
        if (curSpan < minSpan)
            minSpan = curSpan;
    }

    if (minSpan > std::numeric_limits<int>::max() || minSpan < std::numeric_limits<int>::min())
        throw std::overflow_error("Span value out of int range");

    return static_cast<int>(minSpan);
}

int Span::longestSpan( void ) const {
    if (this->_members.size() < 2)
        throw std::runtime_error("Not enough members to compute span");

    int minNum = *std::min_element(this->_members.begin(), this->_members.end());
    int maxNum = *std::max_element(this->_members.begin(), this->_members.end());

    long long span = static_cast<long long>(maxNum) - static_cast<long long>(minNum);
    if (span > std::numeric_limits<int>::max() || span < std::numeric_limits<int>::min())
        throw std::overflow_error("Span value out of int range");

    return static_cast<int>(span);
}
