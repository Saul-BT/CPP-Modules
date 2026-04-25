#ifndef SPAN_CLASS_H
#define SPAN_CLASS_H

#include <stdexcept>
#include <vector>

class Span {

private:

    unsigned int _maxSize;
    std::vector<int> _members;

    Span( unsigned int N );
    Span( Span const & other );
    ~Span();

    Span & operator=( Span const & other );

public:

    void addNumber( int num );
    int shortestSpan( void ) const;
    int longestSpan( void ) const;

    template <typename I>
    void addRange(I begin, I end) {
        unsigned int newSize = std::distance(begin, end) + this->_members.size();
        if (newSize > this->_maxSize)
            throw std::runtime_error("Not enough capacity for this range");

        this->_members.insert(this->_members.end(), begin, end);
    }

};

#endif
