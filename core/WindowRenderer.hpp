#pragma once
#include <SDL2/SDL.h>

class WindowRenderer {
    public:
        WindowRenderer();
        ~WindowRenderer();

        void Run();

    private:
        void HandleEvents();

        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
};