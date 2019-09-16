#include "../../pch.h"

namespace i6
{
    void Engine::set_player(int pos_x, int pos_y)
    {
        player_pos_x = pos_x;
        player_pos_y = pos_y;
    }

    int Engine::get_player_x()
    {
        return player_pos_x;
    }

    int Engine::get_player_y(int query_height)
    {
        return screen_height - query_height - player_pos_y;
    }
}