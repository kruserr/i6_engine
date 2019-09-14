#include "../pch.h"
#include "1/1.cpp"
#include "1/2.cpp"
#include "1/3.cpp"
#include "1/4.cpp"

namespace i6
{
    Engine::Engine()
    {
        #ifndef NDEBUG
        i6::Timer timer;
        #endif

        i6::Render render;

        render.clear_console();

        std::cout << "i6 Engine" << "\n\n";

        results();

        render.hang_console();
    }
}
