#include "../../pch.h"

namespace i6
{    
        Timer::Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        Timer::~Timer()
        {
            end = std::chrono::high_resolution_clock::now();

            duration = end - start;
            ms = duration.count() * 1000.0f;

            std::cout << "\nTimer took: " << ms << " ms\n\n";
        }
}
