#include "../../pch.h"

    unsigned int Proc::validate_threads()
    {
        const unsigned int threads = std::thread::hardware_concurrency();

        if (threads > 0)
            return threads;
        else
            return 1;
    }
