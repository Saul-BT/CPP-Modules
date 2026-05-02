#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <stdexcept>
#include <iterator>
#include <vector>
#include <cstddef>

class Span {

private:

    unsigned int _maxSize;
    std::vector<int> _members;

public:

    Span( void );
    Span( unsigned int N );
    Span( Span const & other );
    ~Span();

    Span & operator=( Span const & other );

    void addNumber( int num );
    int shortestSpan( void ) const;
    int longestSpan( void ) const;

    template <typename I>
    void addRange(I begin, I end) {
        typename std::iterator_traits<I>::difference_type dist = std::distance(begin, end);
        if (dist < 0)
            throw std::runtime_error("Invalid range");
        if (this->_members.size() + static_cast<std::size_t>(dist) > this->_maxSize)
            throw std::runtime_error("Not enough capacity for this range");

        this->_members.insert(this->_members.end(), begin, end);
    }

};

#endif
