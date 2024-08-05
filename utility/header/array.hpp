#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "random.hpp"

namespace utl {

// template<typename T>
class Array {
public:
    Array(unsigned size);
    Array(unsigned size, int min, int max);
    ~Array();

    int operator[](unsigned i);

    void fill_random(const RandGen &rndg);

    void print() const;

private:
    unsigned size;
    int *array;
};

}

#endif // ARRAY_HPP