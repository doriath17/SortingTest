#include "array.hpp"
#include <iostream>

using namespace utl;
using namespace std;

bool utl::check_order(Array &A)
{
    bool ord = true; // ascending order
    for (u32 i=0; i < A.get_lenght()-2 && ord; ++i)
        if (A[i] > A[i+1])
            ord = false;
    return ord;
}


void merge(Array &A, u32 p, u32 q, u32 r)
{
    Array left {q-p+1}, right {r-q};
    for (u32 i=0; i<left.get_lenght(); ++i)
        left[i] = A[p+i];
    for (u32 i=0; i<right.get_lenght(); ++i)
        right[i] = A[q+1+i];

    u32 i=0, j=0, k=p;

    while (i < left.get_lenght() && j < right.get_lenght()){
        if (left[i] <= right[j])
            A[k++] = left[i++];
        else A[k++] = right[j++];
    }
    if (i == left.get_lenght())
        while (j < right.get_lenght())
            A[k++] = right[j++];
    else 
        while (i < left.get_lenght())
            A[k++] = left[i++];
}

void utl::merge_sort(Array &A, u32 p, u32 r)
{
    if (p < r) {
        u32 q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

u32 partitioning(Array &A, i32 p, i32 r)
{
    RandGen rndg(p, r);
    // set the pivot
    i32 tmp = 0, k = rndg.get_rand_int(), x = A[k];
    A[k] = A[p];
    A[p] = x;

    i32 i = p-1, j = r+1;
    do {
        do {
            --j;
        } while (A[j] <= x);
        do {
            ++i;
        } while (A[i] >= x);
        if (i < j){
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    } while(i >= j);
    return j;
}

void utl::quick_sort(Array &A, i32 p, i32 r)
{
    if (p < r){
        i32 q = partitioning(A, p, r);
        quick_sort(A, p, q);
        quick_sort(A, q+1, r);
    }
}