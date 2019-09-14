#include "../../pch.h"
//#include "glm/glm.hpp"
//#include "SDL2/SDL_opengl.h"

namespace i6
{
    int Engine::opengl()
    {
        const int SCREEN_WIDTH  = 1280;
        const int SCREEN_HEIGHT = 720;

        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        }

        SDL_Window *win = SDL_CreateWindow("i6_engine", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (win == nullptr){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (ren == nullptr){
            SDL_DestroyWindow(win);
            std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        SDL_Surface *bmp = SDL_LoadBMP("src/inc/bitmap.bmp");
        if (bmp == nullptr)
        {
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
        SDL_FreeSurface(bmp);
        if (tex == nullptr)
        {
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
        for (int i = 0; i < 10; ++i)
        {
            //First clear the renderer
            SDL_RenderClear(ren);
            //Draw the texture
            SDL_RenderCopy(ren, tex, NULL, NULL);
            //Update the screen
            SDL_RenderPresent(ren);
            //Take a quick break after all that hard work
            SDL_Delay(1000);
        }

        SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();

        return 0;
    }
}
