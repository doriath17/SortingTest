#include "array.hpp"
#include <iostream>

using namespace utl;
using namespace std;

Array::Array(u32 size)
    : size{size}, lenght {size}, array{nullptr}
{
    try {
        array = new int[size];
    } catch(bad_alloc e){
        cout << "Array: Bad allocation.\n";
        throw e;
    }
}

Array::Array(u32 size, i32 min, i32 max)
    : Array(size)
{
    RandGen rndg {min, max};
    fill_random(rndg);
}

Array::~Array()
{
    delete array;
}

u32 Array::get_lenght()
{
    return lenght;
}

i32& Array::operator[](i32 i)
{
    if (i >= lenght) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return array[i];
}

void Array::fill_random(const RandGen &rndg)
{
    for (u32 i=0; i<lenght; ++i)
        array[i] = rndg.get_rand_int();
}

void Array::print() const 
{
    for (unsigned i=0; i<size; ++i)
        cout << array[i] << " ";
    cout << endl;
}

