#include "../../pch.h"

namespace i6
{
    void Proc::debug_info()
    {
        #ifndef NDEBUG
        Render render;

        render.close_console(); // Press enter to exit

        #endif
    }

    unsigned int Proc::validate_threads()
    {
        const unsigned int threads = std::thread::hardware_concurrency();

        if (threads > 0)
            return threads;
        else
            return 1;
    }
}
