#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind( T & container, int target ) {
    typename T::iterator iterator = std::find(container.begin(), container.end(), target);

    if (iterator == container.end())
        throw std::runtime_error("Value not found");

    return iterator;
}