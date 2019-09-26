#include "wall.h"

Wall::Wall()
{
	// Init wall
	set_texture_location("wall");
	set_x(0);
	set_y(0);
	set_solid(true);
}
