#include "../../pch.h"

namespace i6
{
    // Error log
    void Engine::error_log(std::ostream &os, const std::string &msg)
    {
        os << msg << " error: " << SDL_GetError() << '\n';
    }
}
