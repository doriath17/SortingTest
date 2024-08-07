#ifndef UTL_RANDOM_HPP
#define UTL_RANDOM_HPP

#include "utl_typedef.hpp"

namespace utl {

class RandGen {
public:

    RandGen(i32 min, i32 max);
    ~RandGen();

    i32 get_rand_int() const; 
    static i32 get_rand_int(i32 a, i32 b);


    void set_range(i32 min, i32 max);

private:
    i32 min, max;

};

}

#endif // RANDOM_HPP