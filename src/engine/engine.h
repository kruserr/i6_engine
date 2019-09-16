#ifndef ENGINE_H
#define ENGINE_H

namespace i6
{
    class Engine
    {
    private:
        const int screen_width  = 1280;
        const int screen_height = 720;

        int player_pos_x = 0;
        int player_pos_y = 0;
        int player_width = 0;
        int player_height = 0;
        
    public:
        Engine();
        ~Engine();

        // components/maintence.cpp
        template<typename T, typename... Args> void cleanup(T *t, Args&&... args);

        // components/debug.cpp
        void error_log(std::ostream &os, const std::string &msg);

        // components/core.cpp
        bool is_prime(unsigned long long x);
        unsigned long long next_prime(unsigned long long x);
        bool is_prime_threaded(unsigned long long x);
        unsigned long long next_prime_threaded(unsigned long long x);

        // components/texture.cpp
        SDL_Texture* load_texture(const std::string &file, SDL_Renderer *ren);
        void render_texture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

        // components/player.cpp
        void set_player(int pos_x, int pos_y);
        int get_player_x();
        int get_player_y(int query_height);

        // components/game.cpp
        int game_loop();
    };
}

#endif
