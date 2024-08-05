#include "random.hpp"
#include <stdlib.h>
#include <time.h>

#define GET_RAND_INT(min, max) 

using namespace utl;

RandGen::RandGen(int min=0, int max=0)
    : min{min}, max{max}
{

}

RandGen::~RandGen() {}

int RandGen::get_rand_int() const
{
    static uint32_t i = 1;
    if (i == 1){
        srand(time(NULL));
        i = 0;
    }
    return ((min) + (rand() % ((max) - (min) + 1)));
}

void RandGen::set_range(int min, int max)
{
    this->min = min;
    this->max = max;
}
