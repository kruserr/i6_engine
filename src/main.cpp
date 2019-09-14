#include "pch.h"

int main()
{
    #ifndef NDEBUG
    i6::Timer timer;
    #endif

    i6::Render render;
    //i6::Proc proc;
    i6::Engine engine;

    render.clear_console();

    std::cout << "i6 Engine" << "\n\n";

    render.hang_console();
}
