#include "player.h"

	Player::Player()
	{
		// Init player
		set_texture_location("player");
		set_x(0);
		set_y(0);
		keyboard_hold_left = false;
		keyboard_hold_right = false;
		keyboard_hold_up = false;
		keyboard_hold_down = false;
	}

	void Player::keyboard_input(SDL_Event event)
	{
		switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        keyboard_hold_left = true;
                        break;
                    case SDLK_a:
                        keyboard_hold_left = true;
                        break;

                    case SDLK_RIGHT:
                        keyboard_hold_right = true;
                        break;
                    case SDLK_d:
                        keyboard_hold_right = true;
                        break;

                    case SDLK_UP:
                        keyboard_hold_up = true;
                        break;
                    case SDLK_w:
                        keyboard_hold_up = true;
                        break;

                    case SDLK_DOWN:
                        keyboard_hold_down = true;
                        break;
                    case SDLK_s:
                        keyboard_hold_down = true;
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        keyboard_hold_left = false;
                        break;
                    case SDLK_a:
                        keyboard_hold_left = false;
                        break;

                    case SDLK_RIGHT:
                        keyboard_hold_right = false;
                        break;
                    case SDLK_d:
                        keyboard_hold_right = false;
                        break;

                    case SDLK_UP:
                        keyboard_hold_up = false;
                        break;
                    case SDLK_w:
                        keyboard_hold_up = false;
                        break;

                    case SDLK_DOWN:
                        keyboard_hold_down = false;
                        break;
                    case SDLK_s:
                        keyboard_hold_down = false;
                        break;
                }
                break;
        }
	}

	void Player::movement(double aSync)
	{
        // ############################## X Movement ##############################
		if (keyboard_hold_left == true)
		{
			set_hspeed(-player_speed * aSync);
			flip_texture(SDL_FLIP_NONE);
		}

		if (keyboard_hold_right == true)
		{
			set_hspeed(player_speed * aSync);
			flip_texture(SDL_FLIP_HORIZONTAL);
		}

        if (keyboard_hold_left == true && keyboard_hold_right == true)
        {
            set_hspeed(0);
        }
        // ############################## X Movement ##############################

        // ############################## Y Movement ##############################
		if (keyboard_hold_up == true)
        {
			set_vspeed(-player_speed * aSync);
        }

		if (keyboard_hold_down == true)
        {
			set_vspeed(player_speed * aSync);
        }

        if (keyboard_hold_up == true && keyboard_hold_down == true)
        {
            set_vspeed(0);
        }
        // ############################## Y Movement ##############################


        // ############################## 0 Movement ##############################
		if (keyboard_hold_left == false && keyboard_hold_right == false)
			set_hspeed(0);
		if (keyboard_hold_up == false && keyboard_hold_down == false)
			set_vspeed(0);
        // ############################## 0 Movement ##############################
	}
