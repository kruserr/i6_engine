#include "../../pch.h"
#include "maintence.cpp"
#include "debug.cpp"
#include "game/gamelogic.h"


    double Engine::game_loop()
    {

        // Scoped Variables
        bool quit = false;

        // Init
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            //error_log(std::cout, "SDL_Init");
            
            return 1;
        }

        // Init Window
        //SDL_Window *window = SDL_CreateWindow("i6_engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        SDL_Window *window = SDL_CreateWindow("i6_engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            //error_log(std::cout, "CreateWindow");
            SDL_Quit();

            return 1;
        }

        // Init Renderer
        //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
        {
            //error_log(std::cout, "CreateRenderer");
            cleanup(window);
            SDL_Quit();

            return 1;
        }

		//INIT GAMELOGIC
		GameLogic gamelogic(renderer);
		gamelogic.initilize();

        // Game Loop
        while (!quit)
        {
            // Animation Sync
            gamelogic.set_sync_start();

			// Event
            SDL_Event event;
            SDL_PollEvent(&event);

            // Clear Renderer
            SDL_RenderClear(renderer);

            // Game Logic
			gamelogic.loop(&event);

			// Check if loop shall end
			if (event.type == SDL_QUIT)
				quit = true;

            SDL_RenderPresent(renderer);

            // Animation Sync
            gamelogic.set_sync_end();
        }

        // Clean and Exit
        cleanup(renderer, window);
        SDL_Quit();

        return 0;
    }
