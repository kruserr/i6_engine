#include "pch.h"

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
int main(int argc, char *argv[])
#elif defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__) || defined(__MINGW64__)
int WinMain()
#endif
{
    #ifndef NDEBUG
    Timer timer;
    #endif

    Engine engine;

	return 0;
}
