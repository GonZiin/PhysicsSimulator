#include "Circle.hpp"

void Circle::DrawCircle(SDL_Renderer* renderer, int cX, int cY, int radius, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    int x = 0;
    int y = radius;
    int d = 3 - (2 * radius);

    while (x <= y) {
        SDL_RenderDrawPoint(renderer, cX + x, cY + y);
        SDL_RenderDrawPoint(renderer, cX - x, cY + y);
        SDL_RenderDrawPoint(renderer, cX + x, cY - y);
        SDL_RenderDrawPoint(renderer, cX - x, cY - y);
        SDL_RenderDrawPoint(renderer, cX + y, cY + x);
        SDL_RenderDrawPoint(renderer, cX - y, cY + x);
        SDL_RenderDrawPoint(renderer, cX + y, cY - x);
        SDL_RenderDrawPoint(renderer, cX - y, cY - x);

        if (d < 0) {
            d = d + (4 * x) + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void Circle::DrawFillCircle(SDL_Renderer* renderer, int cX, int cY, int radius, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    int x = 0;
    int y = radius;
    int d = 3 - (2 * radius);

    while (x <= y) {
        SDL_RenderDrawLine(renderer, cX - x, cY - y, cX + x, cY - y);
        SDL_RenderDrawLine(renderer, cX - x, cY + y, cX + x, cY + y);        
        SDL_RenderDrawLine(renderer, cX - y, cY - x, cX + y, cY - x);
        SDL_RenderDrawLine(renderer, cX - y, cY + x, cX + y, cY + x);

        if (d < 0) {
            d = d + (4 * x) + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}