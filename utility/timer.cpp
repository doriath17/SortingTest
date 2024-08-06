#include "timer.hpp"

using namespace utl;
using namespace std::chrono;
using namespace std::chrono_literals;


Timer::Timer(callback_t func, void *args)
    : func{func}, args{args}
{
    start = selected_clock::now();
    end = selected_clock::now();
}

Timer::~Timer() {}


void Timer::take_exec_time()
{
    start = selected_clock::now();
    func(args);
    end = selected_clock::now();
}

void Timer::print_duration(TimerRatio tr) const
{   
    int num, den;
    std::string str("--");
    duration<float, std::milli> d(end - start);
    switch (tr){
        case TimerRatio::ms:
            num = 1;
            den = 1000;
            str = "ms";
            break;
        default: 
            std::cout << "not supported: timer ratio.\n";
            break;
    }
    std::cout << "Durata esecuzione: " << d.count() << str << std::endl;
}