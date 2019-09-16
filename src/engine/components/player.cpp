#include "../../pch.h"

namespace i6
{
    void Engine::set_player_x(int pos_x)
    {
        player_pos_x = pos_x;
    }

    void Engine::set_player_y(int pos_y)
    {
        player_pos_y = pos_y;
    }

    int Engine::get_player_x()
    {
        return player_pos_x;
    }

    int Engine::get_player_y()
    {
        return player_pos_y;
    }

    int Engine::compute_player_x()
    {
        return player_pos_x;
    }

    int Engine::compute_player_y(int query_height)
    {
        return screen_height - query_height - player_pos_y;
    }

    bool Engine::move_player(SDL_Event event)
    {
        /* Proc proc;

        bool quit = false;

        int cpus = proc.validate_threads();

        std::vector<std::thread> threads(cpus);
        std::mutex iomutex;

        for (int i = 0; i < cpus; i++)
        {
            threads[i] = std::thread( [&]
            {
                //std::lock_guard<std::mutex> iolock(iomutex);
                switch (event.type)
                {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_LEFT:
                                set_player(get_player_x() - 1, get_player_y());
                                break;
                            case SDLK_RIGHT:
                                set_player(get_player_x() + 1, get_player_y());
                                break;
                            case SDLK_UP:
                                set_player(get_player_x(), get_player_y() + 1);
                                break;
                            case SDLK_DOWN:
                                set_player(get_player_x(), get_player_y() - 1);
                                break;
                        }
                        break;
                }
            } );
        }

        for (auto& t : threads)
            t.join();

        if (!quit)
            return false;
        else
            return true; */

        switch (event.type)
        {
            case SDL_QUIT:
                return true;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        set_player_x(get_player_x() - 1);
                        return false;
                    case SDLK_RIGHT:
                        set_player_x(get_player_x() + 1);
                        return false;
                    case SDLK_UP:
                        set_player_y(get_player_y() + 1);
                        return false;
                    case SDLK_DOWN:
                        set_player_y(get_player_y() - 1);
                        return false;
                }
                return false;
        }

        return false;
    }
}