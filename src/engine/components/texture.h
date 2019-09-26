#ifndef TEXTURE_H
#define TEXTURE_H

#include "..//engine.h"

struct RenderObject
{
	SDL_Texture* tex;
	SDL_Renderer* ren;
	double x;
	double y;
	double angle;
};

class Texture
{
private:
	SDL_RendererFlip fliptype = SDL_FLIP_NONE;
	std::list<RenderObject> render_queue;

public:
	// components/texture.cpp
	SDL_Texture* load_texture(const std::string& file, SDL_Renderer* ren);
	void render_texture(SDL_Texture* tex, SDL_Renderer* ren, double x, double y, double aAngle);
	void render_texture_ext(SDL_Texture* texture, SDL_Renderer* renderer, double x, double y, double aAngle, double aWidth, double aHeight);
	void set_flip_type(SDL_RendererFlip aFlipType) { fliptype = aFlipType; }
	std::list<RenderObject>& get_render_queue() { return render_queue; }
	void render_queue_push(SDL_Texture* aTex, SDL_Renderer* aRen, double aX, double aY, double aAngle);
};

#endif // !TEXTURE_H
