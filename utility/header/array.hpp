#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "random.hpp"

namespace utl {

// template<typename T>
/// @brief Array has two variables: size and lenght.
class Array {
public:
    /// @brief this constructor set the lenght to size
    /// @param size the size in memory 
    Array(unsigned size);

    /// @brief this constructor set the lenght to size. Elements are initialized 
    /// in the interval [min, max].
    /// @param size the size in memory 
    Array(unsigned size, int min, int max);
    ~Array();

    int operator[](unsigned i);

    void fill_random(const RandGen &rndg);

    void print() const;

private:
    unsigned size, lenght;
    int *array;
};

}

#endif // ARRAY_HPP