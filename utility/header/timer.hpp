#ifndef UTL_TIMER_HPP
#define UTL_TIMER_HPP

#include <iostream>
#include <chrono>

namespace utl {

enum class TimerRatio {ms, us};

class Timer {
public: 
    // the void ptr will allow passing multiple arguments to some function.
    // you should have a callback version of the function you want to test out
    // that will make the appropriate call with actual parameters. 
    using callback_t = void (*)(void *); 
    Timer(callback_t func, void *args);
    ~Timer();

    void take_exec_time();

    void print_duration(TimerRatio tr) const;

private:
    using selected_clock = std::chrono::steady_clock;
    using time_p = std::chrono::time_point<selected_clock>;
    time_p start, end;
    callback_t func;
    void *args;
};


}

#endif // UTL_TIMER_HPP
