#ifndef ENGINE_H
#define ENGINE_H

namespace i6
{
    class Engine
    {
    private:
        const double screen_width  = 1280;
        const double screen_height = 720;

        double player_pos_x = 0;
        double player_pos_y = 0;
        double player_width = 0;
        double player_height = 0;
        double player_speed = 1;
        
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
        void render_texture(SDL_Texture *tex, SDL_Renderer *ren, double x, double y);

        // components/player.cpp
        void set_player_x(double pos_x);
        void set_player_y(double pos_y);
        void set_player_width(double width);
        void set_player_height(double height);
        void set_player_speed(double speed);
        double get_player_x();
        double get_player_y();
        double compute_player_x();
        double compute_player_y(double query_height);
        bool move_player(SDL_Event event);

        // components/game.cpp
        double game_loop();
    };
}

#endif
