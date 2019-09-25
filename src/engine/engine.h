#ifndef ENGINE_H
#define ENGINE_H

#include "..//pch.h"

const double screen_width = 1080;
const double screen_height = 720;
const double camera_speed = 100;
extern double screen_x_origon;
extern double screen_y_origon;
extern double camera_pos_x;
extern double camera_pos_y;
extern double camera_pos_x_old;
extern double camera_pos_y_old;
extern double delta_camera_pos_x;
extern double delta_camera_pos_y;

    class Engine
    {
    private:

    public:
        Engine();
        ~Engine();

        // components/core.cpp
        /* bool is_prime(unsigned long long x);
        unsigned long long next_prime(unsigned long long x);
        bool is_prime_threaded(unsigned long long x);
        unsigned long long next_prime_threaded(unsigned long long x); */

        // components/game.cpp
        double game_loop();
    };

#endif
