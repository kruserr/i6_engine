#include "../pch.h"
#include "1/1.cpp"
#include "1/2.cpp"
#include "1/3.cpp"
#include "1/4.cpp"

namespace i6
{
    Engine::Engine()
    {
        i6::Render render;
        render.clear_console();

        //long x = 21474913;
        //unsigned long long x = 2147483647;
        //unsigned long long x = 67280421310721;
        //unsigned long long x = 672804213107214533;
        //u_int64_t x = 18446744073709600000;
        unsigned long long x = 9223372036854770027;

        std::cout << next_prime_threaded(x) << '\n';

        std::cout << is_prime_threaded(x) << '\n';
        std::cout << is_prime_threaded(x) << '\n';
        std::cout << is_prime_threaded(x) << "\n\n";
    }

    Engine::~Engine()
    {
        i6::Render render;

        render.hang_console();
    }
}
