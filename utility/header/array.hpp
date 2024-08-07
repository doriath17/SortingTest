#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "utl_typedef.hpp"
#include "random.hpp"

namespace utl {

// template<typename T>
/// @brief Array has two variables: size and lenght.
class Array {
public:
    /// @brief this constructor set the lenght to size
    /// @param size the size in memory 
    Array(u32 size);

    /// @brief this constructor set the lenght to size. Elements are initialized 
    /// in the interval [min, max].
    /// @param size the size in memory 
    Array(u32 size, i32 min, i32 max);
    ~Array();

    u32 get_lenght();

    i32& operator[](i32 i);

    void fill_random(const RandGen &rndg);

    void print() const;
    
    friend void quick_sort(Array *A, u32 p, u32 r);


private:
    u32 size, lenght;
    i32 *array;

};

bool check_order(Array &A);

/// @brief 
/// @param A 
/// @param p should be 0 
/// @param r should be A.lenght - 1
void merge_sort(Array &A, u32 p, u32 r);


/// @brief 
/// @param A 
/// @param p should be 0 
/// @param r should be A.lenght - 1
void quick_sort(Array &A, i32 p, i32 r);


}

#endif // ARRAY_HPP