#include "../pch.h"
#include "components/maintence.cpp"

	//CAMERA POSITION
	double camera_pos_x = 0;
	double camera_pos_y = 0;
	double screen_x_origon = 0;
	double screen_y_origon = 0;
	double camera_pos_x_old = camera_pos_x;
	double camera_pos_y_old = camera_pos_y;
	double delta_camera_pos_x = 0;
	double delta_camera_pos_y = 0;

    Engine::Engine()
    {
        game_loop();
    }

    Engine::~Engine()
    {
        
    }
