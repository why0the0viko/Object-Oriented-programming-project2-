#include <SDL2/SDL.h>
#include <iostream>
#include "Rectangle.h"
#include "circle.h"
#include "square.h"

int main(int argv, char** args)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std :: cout <<" Failed to initialize the SDL2 library " << std :: endl;
        return -1;
    }
    SDL_Window * window = SDL_CreateWindow("SDL Window",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    750, 750,
    0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);;
    if(!window)
    {
        std :: cout << " Failed to create window " << std :: endl;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        std :: cout << "Failed to get the surface from the window " << std :: endl;
        return -1;
    }

    SDL_UpdateWindowSurface(window);
    
    bool keep_window_open = true;
    Rectangle temp(275, 275, 18, 45);
    circle temC(49, 375, 375);
    square tems(12, 75, 45);
    while(keep_window_open)
    {
        SDL_Event e;
        SDL_RenderClear(renderer);
        while(SDL_PollEvent(&e) > 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
            SDL_UpdateWindowSurface(window);
        }
        temC.drawCircle(renderer, window);
        temp.draw(renderer, window);
        tems.draw(renderer, window);
        SDL_RenderPresent(renderer);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}