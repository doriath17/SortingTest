#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdint>

namespace utl {

class RandGen {
public:

    RandGen(int min, int max);
    ~RandGen();

    int get_rand_int() const; 

    void set_range(int min, int max);

private:
    int min, max;

};

}

#endif // RANDOM_HPP