#include "array.hpp"
#include <iostream>

using namespace utl;
using namespace std;

Array::Array(unsigned size)
    : size{size}
{
    try {
        array = new int[size];
    } catch(bad_alloc e){
        cout << "Array: Bad allocation.\n";
        throw e;
    }
}

Array::Array(unsigned size, int min, int max)
    : Array(size)
{
    RandGen rndg {min, max};
    fill_random(rndg);
}

Array::~Array()
{
    delete array;
}

int Array::operator[](unsigned i)
{
    return array[i];
}

void Array::fill_random(const RandGen &rndg)
{
    for (unsigned i=0; i<size; ++i)
        array[i] = rndg.get_rand_int();
}

void Array::print() const 
{
    for (unsigned i=0; i<size; ++i)
        cout << array[i] << " ";
    cout << endl;
}