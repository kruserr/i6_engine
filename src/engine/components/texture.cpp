#include "../../pch.h"
#include "maintence.cpp"
#include "debug.cpp"
#include "texture.h"

SDL_Texture* Texture::load_texture(const std::string& file, SDL_Renderer* renderer, SDL_Texture *texture, SDL_Surface *loadedImage)
{
	std::string inc_dir;

	// Load the image
	inc_dir = "inc/assets/";
	inc_dir.append(file);
	inc_dir.append(".bmp");
	loadedImage = SDL_LoadBMP(inc_dir.c_str());

	// If path fails try new path
	if (loadedImage == nullptr)
	{
		inc_dir = "src/inc/assets/";
		inc_dir.append(file);
		inc_dir.append(".bmp");
		loadedImage = SDL_LoadBMP(inc_dir.c_str());
	}

	// If path fails try new path
	if (loadedImage == nullptr)
	{
		inc_dir = "SDLproject/src/inc/assets/";
		inc_dir.append(file);
		inc_dir.append(".bmp");
		loadedImage = SDL_LoadBMP(inc_dir.c_str());
	}

	// If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr)
	{
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		//cleanup(loadedImage);

		// Make sure converting went ok too
		if (texture == nullptr)
		{
			//error_log(std::cout, "CreateTextureFromSurface");
		}
	}
	else
	{
		//cleanup(loadedImage);
		//error_log(std::cout, "LoadBMP");
	}

	return texture;
}

void Texture::render_texture(SDL_Texture* texture, SDL_Renderer* renderer, double x, double y, double aAngle)
{
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	

	//Query the texture to get its width and height to use
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopyEx(renderer, texture, NULL, &dst, aAngle, NULL, fliptype);
}

void Texture::render_texture_ext(SDL_Texture* texture, SDL_Renderer* renderer, double x, double y, double aAngle, double aWidth, double aHeight)
{
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;

	//Query the texture to get its width and height to use
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	dst.w = aWidth;
	dst.h = aHeight;
	SDL_RenderCopyEx(renderer, texture, NULL, &dst, aAngle, NULL, fliptype);
}
