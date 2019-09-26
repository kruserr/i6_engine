#ifndef TIMER_H
#define TIMER_H

// Timer Function
struct Timer
{
private:

public:
    #if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(__MINGW32__) || defined(__MINGW64__)
    std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::nanoseconds> start, end;
    
    #elif defined(_WIN32) || defined(_WIN64)
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> start, end;

    #endif
    
    std::chrono::duration<float> duration;
    float ms;

    Timer();
    ~Timer();
};

#endif
