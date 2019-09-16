#include "../../pch.h"

namespace i6
{
    int Engine::game_loop()
    {
        SDL_Event event;
        
        bool quit = false;
        int query_width = 0;
        int query_height = 0;

        // Init
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            error_log(std::cout, "SDL_Init");
            
            return 1;
        }

        // Init Window
        SDL_Window *window = SDL_CreateWindow("i6_engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            error_log(std::cout, "CreateWindow");
            SDL_Quit();

            return 1;
        }

        // Init Renderer
        //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
        {
            error_log(std::cout, "CreateRenderer");
            cleanup(window);
            SDL_Quit();

            return 1;
        }

        // Load Textures
        SDL_Texture *image = load_texture("/stick_figure/stick_figure.bmp", renderer);
        SDL_QueryTexture(image, NULL, NULL, &query_width, &query_height);

        // Game Loop
        while (!quit)
        {
            // Poll event
            SDL_Delay(4);
            SDL_PollEvent(&event);

            // Move Player
            quit = move_player(event);

            // Clear Renderer
            SDL_RenderClear(renderer);

            // Render Image
            SDL_QueryTexture(image, NULL, NULL, &query_width, &query_height);
            render_texture(image, renderer, compute_player_x(), compute_player_y(query_height));

            // Render Renderer
            SDL_RenderPresent(renderer);
        }

        // Clean and Exit
        cleanup(image);
        cleanup(renderer, window);
        SDL_Quit();

        return 0;
    }
}
