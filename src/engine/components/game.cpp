#include "../../pch.h"
#include "maintence.cpp"
#include "debug.cpp"
#include "game/gamelogic.h"

double Engine::game_loop()
{
    // Scoped Variables
    bool quit = false;
    int screen_mode = -1;
    SDL_Window *window = nullptr;

    // Init
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    //if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        //error_log(std::cout, "SDL_Init");
        
        return 1;
    }

    // Settings
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    // Display Config
    SDL_DisplayMode current_screen;
    //SDL_GetNumVideoDisplays();
    //SDL_GetCurrentDisplayMode(0, &current_screen);
    SDL_GetDesktopDisplayMode(0, &current_screen);
    //std::cout << current_screen.h << "; " << current_screen.w << "; " << current_screen.refresh_rate << '\n';

    // Init Window
    if (screen_mode == 0)
        window = SDL_CreateWindow("i6_engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_FULLSCREEN_DESKTOP);
    else if (screen_mode == 1)
        window = SDL_CreateWindow("i6_engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, current_screen.w, current_screen.h, SDL_WINDOW_BORDERLESS);
    else
        window = SDL_CreateWindow("i6_engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);

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

    // Event
    SDL_Event event;

    //INIT GAMELOGIC
    GameLogic gamelogic(renderer);
    gamelogic.initilize();
    
    // Game Loop
    while (!quit)
    {
        // Event
        SDL_PollEvent(&event);

        // Animation Sync
        gamelogic.set_sync_start();

        // Clear Renderer
        SDL_RenderClear(renderer);

        // Game Logic
        gamelogic.loop(&event);

        // Render Loop
        gamelogic.r_loop();

        SDL_RenderPresent(renderer);

        // Animation Sync
        gamelogic.set_sync_end();

        // Exit
        if (event.type == SDL_QUIT)
            quit = true;
    }

    // Clean and Exit
    cleanup(renderer, window);
    SDL_Quit();

    return 0;
}
