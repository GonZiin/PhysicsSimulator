#pragma once
#include <SDL2/SDL.h>

class WindowRenderer {
    public:
        WindowRenderer();
        WindowRenderer(const char* title, int width, int height);
        ~WindowRenderer();

        void Run();

    private:
        void HandleEvents();

        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
};