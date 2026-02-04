#include <stdio.h>
#include <SDL2/SDL.h> //graphic library of C

int main()
{
    // Intialize a Window
    SDL_Init(SDL_INIT_VIDEO);

    // Parameters to set it to centre of the screen and give the size.
    SDL_Window *window = SDL_CreateWindow("3D Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    
    // size of the shape
    SDL_Rect rect = (SDL_Rect) {40, 40, 30, 60};
    
    // color of shape = white
    SDL_FillRect(surface, &rect, 0xffffffff);
    SDL_UpdateWindowSurface(window);
    
    
    // Hold the window for 5 seconds
    SDL_Delay(5000);
}