#pragma once
#include <SDL2/SDL.h>

class Circle {
    public:
        static void DrawCircle(SDL_Renderer* renderer, int x, int y, int radius, SDL_Color color);
        static void DrawFillCircle(SDL_Renderer* renderer, int x, int y, int radius, SDL_Color color);
};