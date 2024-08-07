#include <iostream>
#include "utility.hpp"

/* 
TODO: algoritmi di ordinamento
*/

using namespace utl;
using namespace std;


void run(Array &arr)
{
    merge_sort(arr, 0, arr.get_lenght()-1);
}

void run_callback(void *args)
{
    Array *arr = (Array *) args;
    run(*arr);
}

int main()
{
    Array arr {(u32) 10e8, 1, 99};
    Timer timer1 {run_callback, (void *) &arr};
    timer1.take_exec_time();
    timer1.print_duration(TimerRatio::min);
    cout << "ord = " << check_order(arr) << endl;
    return 0;
}