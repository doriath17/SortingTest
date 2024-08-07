#include "timer.hpp"

using namespace utl;
using namespace std::chrono;
using namespace std::chrono_literals;
using namespace std::literals;

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
    duration<i64, std::nano> d((end - start)/1us);
    i64 ticks = d.count(); // total nano seconds
    i64 tot_ms = ticks / 1000, ns = ticks - tot_ms * 1000;
    i64 tot_s = tot_ms / 1000, ms = tot_ms - tot_s * 1000;
    i64 tot_min = tot_s / 60, s = tot_s - tot_min * 60;
    i64 tot_h = tot_min / 60, min = tot_min - tot_h * 60;

    std::cout << min << "min " << s << "s " << ms << "ms " << ns << "ns\n";
}