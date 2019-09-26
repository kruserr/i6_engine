#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "..//texture.h"

class GameObject : Texture
{
private:
	SDL_Renderer* renderer;
	SDL_Texture* image;
	std::string texture_location;
	double texture_x;
	double texture_y;
	double width;
	double height;
	double x;
	double y;
	double xPrevious;
	double yPrevious;
	double hspeed;
	double vspeed;
	double angle;
	bool place_texture_automaticly;
	bool solid;

public:
	GameObject();
	~GameObject();

	void init();
	void refresh();

	void setRenderer(SDL_Renderer& aRenderer) { renderer = &aRenderer; }
	void set_texture_width(double aWidth) { width = aWidth; }
	void set_texture_height(double aHeight) { height = aHeight; }
	double get_texture_width() { return width; }
	double get_texture_height() { return height; }
	void set_texture_x(double aX) { texture_x = aX; }
	void set_texture_y(double aY) { texture_y = aY; }
	double get_texture_x() { return texture_x; }
	double get_texture_y() { return texture_y; }
	void setAngle(double aAngle) { angle = aAngle; }
	double getAngle() { return angle; }
	void set_texture_location(std::string aTexture_location) { texture_location = aTexture_location; }
	void flip_texture(SDL_RendererFlip aFlip) { set_flip_type(aFlip); }

	// Position
	void set_x(double aPos_x);
	void set_y(double aPos_y);
	void set_width(double aWidth);
	void set_height(double aHeight);
	void set_hspeed(double aHspeed);
	void set_vspeed(double aVspeed);
	double get_hspeed();
	double get_vspeed();
	double get_x();
	double get_y();
	double get_x_previous();
	double get_y_previous();
	void auto_place_texture(bool aChoice);
	void set_solid(bool aChoice);
	bool collides_with(GameObject *other);
};

#endif // !GAMEOBJECT_H
