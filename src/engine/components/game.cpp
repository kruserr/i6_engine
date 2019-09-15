#include "../../pch.h"

namespace i6
{
    int Engine::game_loop()
    {
        int query_width, query_height;

        // Init
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            error_log(std::cout, "SDL_Init");
            
            return 1;
        }

        // Init Window
        SDL_Window *window = SDL_CreateWindow("i6_engine", 100, 100, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            error_log(std::cout, "CreateWindow");
            SDL_Quit();

            return 1;
        }

        // Init Renderer
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr)
        {
            error_log(std::cout, "CreateRenderer");
            cleanup(window);
            SDL_Quit();

            return 1;
        }

        // Load Textures
        SDL_Texture *background = load_texture("background.bmp", renderer);
        SDL_Texture *image = load_texture("image.bmp", renderer);

        // Game Loop
        for (int i = 0; i < 3; i++)
        {
            // Clear Renderer
            SDL_RenderClear(renderer);

            // Render Background
            SDL_QueryTexture(background, NULL, NULL, &query_width, &query_height);
            for (int width = query_width; width <= screen_width; width += query_width)
                for (int height = query_height; height <= screen_height; height += query_height)
                    render_texture(background, renderer, screen_width - width, screen_height - height);
            
            // Render Image
            SDL_QueryTexture(image, NULL, NULL, &query_width, &query_height);
            render_texture(image, renderer, (screen_width - query_width) / 2, (screen_height - query_width) / 2);

            // Render Renderer
            SDL_RenderPresent(renderer);

            // Sleep 1s
            SDL_Delay(1000);
        }

        // Clean and Exit
        cleanup(background);
        cleanup(image);
        cleanup(renderer, window);
        SDL_Quit();

        return 0;
    }
}
