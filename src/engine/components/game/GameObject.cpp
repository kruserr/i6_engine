#include "GameObject.h"
#include "../maintence.cpp"

#include <iostream>

GameObject::GameObject()
{
	renderer = nullptr;
	texture_location = "";
	width = 0;
	height = 0;
	texture_x = 0;
	texture_y = 0;
	x = 0;
	y = 0;
	xPrevious = x;
	yPrevious = y;
	hspeed = 0;
	vspeed = 0;
	angle = 0;
	place_texture_automaticly = true;
	solid = false;
}

GameObject::~GameObject()
{
	cleanup(image);
}

void GameObject::init()
{
	int tempWidth = 0;
	int tempheight = 0;

	// Load Textures
	image = load_texture(texture_location, renderer);
	SDL_QueryTexture(image, NULL, NULL, &tempWidth, &tempheight);
	set_texture_width(tempWidth);
	set_texture_height(tempheight);
}

void GameObject::refresh()
{
	xPrevious = x;
	yPrevious = y;

	// Render Image
	//render_texture(image, renderer, texture_x, texture_y, angle);

	render_queue_push(image, renderer, texture_x, texture_y, angle);

	// Set texture appropratly
	if (place_texture_automaticly)
	{
		texture_x = x;
		texture_y = y;
	}

	// set new position of player based on camera position
	x = x - delta_camera_pos_x + hspeed;
	y = y - delta_camera_pos_y + vspeed;

}

// Validates whever a game object has collided with another game object
bool GameObject::collides_with(GameObject *other)
{
	bool collision_detected = false;

	if ((x + width > other->x) && (x < other->x + other->width) && (y + height > other->y) && (y < other->y + other->height))
	{
		if (other->solid == true)
		{
			collision_detected = true; 
		}
	}

	std::cout << collision_detected << std::endl;
	return collision_detected;
}

void GameObject::set_x(double aPos_x) { x = aPos_x; }
void GameObject::set_y(double aPos_y) { y = aPos_y; }
void GameObject::set_width(double aWidth) { width = aWidth; }
void GameObject::set_height(double aHeight) { height = aHeight; }
void GameObject::set_hspeed(double aHspeed) { hspeed = aHspeed; }
void GameObject::set_vspeed(double aVspeed) { vspeed = aVspeed; }
double GameObject::get_hspeed() { return hspeed; }
double GameObject::get_vspeed() { return hspeed; }
double GameObject::get_x() { return x; }
double GameObject::get_y() { return y; }
double GameObject::get_x_previous() { return xPrevious; };
double GameObject::get_y_previous() { return yPrevious; };
void GameObject::auto_place_texture(bool aChoice) { place_texture_automaticly = aChoice; }
void GameObject::set_solid(bool aChoice) { solid = aChoice; }


void GameObject::render_queue_push(SDL_Texture* aTex, SDL_Renderer* aRen, double aX, double aY, double aAngle)
{
	//std::list<RenderObject> list;

	RenderObject r;
	r.tex = aTex;
	r.ren = aRen;
	r.x = aX;
	r.y = aY;
	r.angle = aAngle;

	//std::cout << "render_queue_push: aTex: " << aTex << '\n';

	render_queue.push_back(r);
	//set_render_queue(list);

	//std::cout << "render_queue_push: render_queue.size(): " << render_queue.size() << '\n';
	//std::cout << "render_queue_push: list.size(): " << list.size() << '\n';
}

void GameObject::render_loop()
{
	auto i = render_queue.begin();
	render_texture(i->tex, i->ren, i->x, i->y, i->angle);
	//std::cout << "render_loop: size(): " << render_queue.size() << '\n';

	//std::cout << "render_queue_push: aTex: " << i->tex << '\n';

	if (render_queue.size() > 0)
		render_queue.pop_front();
}
