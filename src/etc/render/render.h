#ifndef RENDER_H
#define RENDER_H

namespace i6
{
    // Rendering Functions
    class Render
    {
    private:

    public:
        std::string input(std::string input, int option = 1);
        long int random(long int start = -2147483647, long int end = 2147483647);
        void clear_console();
        void hang_console();
        void close_console();
    };
}

#endif
