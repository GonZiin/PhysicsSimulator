#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "../physics/Particle.hpp"

class WindowRenderer {
public:
    WindowRenderer(const char* title = "Physics Simulator", int width = 1280, int height = 720);
    ~WindowRenderer();

    void Run();

private:
    void HandleEvents();
    void Update(float dt);
    void Render();

    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    std::vector<Particle> particles;
    Uint64 lastFrameTime; // Variável para guardar o tempo
};