#include "../pch.h"
#include "components/maintence.cpp"
#include "components/debug.cpp"
#include "components/core.cpp"
#include "components/texture.cpp"
#include "components/game.cpp"

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
        /* unsigned long long x = 9223372036854770027;

        std::cout << next_prime_threaded(x) << '\n';

        std::cout << is_prime_threaded(x) << '\n';
        std::cout << is_prime_threaded(x) << '\n';
        std::cout << is_prime_threaded(x) << "\n\n"; */

        game_loop();
    }

    Engine::~Engine()
    {
        i6::Render render;

        render.hang_console();
    }
}
