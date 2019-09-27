#ifndef PLAYER_H
#define PLAYER_H

#include "..//GameObject.h"

class Player : public GameObject
{
private:
	bool keyboard_hold_left, keyboard_hold_right, keyboard_hold_up, keyboard_hold_down;
    double player_speed = 0.6;
	double player_angle, delta_x_norm, delta_y_norm;
	Sint32 mouse_x, mouse_y, delta_x, delta_y;

public:
	Player();

	//gameobject components
	void gameObjectRun() { refresh(); }

	void keyboard_input(SDL_Event event);
	void movement(double aSync);

	double get_player_speed() { return player_speed; }
};

#endif // !PLAYER_H
