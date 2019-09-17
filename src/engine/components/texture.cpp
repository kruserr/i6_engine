namespace i6
{
    SDL_Texture* Engine::load_texture(const std::string &file, SDL_Renderer *renderer)
    {
        // Initialize to nullptr to avoid dangling pointer issues
        SDL_Texture *texture = nullptr;

        // Load the image
        std::string inc_dir = "src/inc/";
        inc_dir.append(file);
        SDL_Surface *loadedImage = SDL_LoadBMP(inc_dir.c_str());

        // If path fails try new path
        if (loadedImage == nullptr)
        {
            inc_dir = "../src/inc/";
            inc_dir.append(file);
            loadedImage = SDL_LoadBMP(inc_dir.c_str());
        }

        // If the loading went ok, convert to texture and return the texture
        if (loadedImage != nullptr)
        {
            texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
            cleanup(loadedImage);

            // Make sure converting went ok too
            if (texture == nullptr)
            {
                error_log(std::cout, "CreateTextureFromSurface");
            }
        }
        else
        {
            error_log(std::cout, "LoadBMP");
        }

        return texture;
    }

    void Engine::render_texture(SDL_Texture *texture, SDL_Renderer *renderer, double x, double y)
    {
        //Setup the destination rectangle to be at the position we want
        SDL_Rect dst;
        dst.x = x;
        dst.y = y;

        //Query the texture to get its width and height to use
        SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
        SDL_RenderCopy(renderer, texture, NULL, &dst);
    }   
}
