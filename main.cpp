#include <iostream>
#include <ratio>
#include "utility.hpp"

/* 
TODO: timer / exec stats
TODO: algoritmi di ordinamento
*/

void run()
{
    for (int i=0; i<1000000000; ++i)
        ;
}

void run_callback(void *args)
{
    run();
}

using namespace utl;
int main()
{
    Timer timer1 {run_callback, nullptr};
    // Array arr {10, 1, 99};
    // arr.print();
    timer1.take_exec_time();
    timer1.print_duration(TimerRatio::ms);
    
    return 0;
}