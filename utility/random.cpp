#include "random.hpp"
#include <stdlib.h>
#include <time.h>

#define GET_RAND_INT(min, max) 

using namespace utl;

RandGen::RandGen(i32 min=0, i32 max=0)
    : min{min}, max{max}
{

}

RandGen::~RandGen() {}

int RandGen::get_rand_int() const
{
    static u32 i = 1;
    if (i == 1){
        srand(time(NULL));
        i = 0;
    }
    return ((min) + (rand() % ((max) - (min) + 1)));
}

i32 RandGen::get_rand_int(i32 min, i32 max)
{
    static u32 i = 1;
    if (i == 1){
        srand(time(NULL));
        i = 0;
    }
    return ((min) + (rand() % ((max) - (min) + 1)));
}

void RandGen::set_range(i32 min, i32 max)
{
    this->min = min;
    this->max = max;
}
